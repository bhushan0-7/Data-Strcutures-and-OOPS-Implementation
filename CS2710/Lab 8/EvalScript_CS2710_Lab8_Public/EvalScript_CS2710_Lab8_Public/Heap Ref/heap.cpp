#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

Heap::Heap(int maxN/* = 20 */, int *ele/* = NULL */) {
	this->maxN = maxN;
	if (ele == NULL)
		elements = new ElementType[maxN];
	else
		elements = ele;
	nelements = 0;
}
int Heap::percolateUp(int ii) {
	int iiancestor = getParent(ii);
	int e = elements[ii];	// important.

	while (iiancestor && e > elements[iiancestor]) {	// for minheap, change > to <
		elements[ii] = elements[iiancestor];
		ii = iiancestor;
		iiancestor = getParent(ii);
	}

	return ii;	// new position.
}
int Heap::insert(ElementType e) {
	cout << "inserting " << e << endl;
	if (nelements + 1 == maxN) {
		cerr << "Heap overflow on inserting " << e << endl;
		return 0;
	}
	elements[++nelements] = e;	// insert at the end, index starts at 1.
	int ii = percolateUp(nelements);
	elements[ii] = e;		// finally insert at the right place.
	return ii;
}
int Heap::percolateDown(int iparent, bool checklast/* = true*/) {
	ElementType emax = elements[iparent];
	ElementType elast = elements[nelements];	// important.

	while (iparent < nelements) {
		int ileft = getLeft(iparent);
		int iright = getRight(iparent);

		ElementType eleftchild = NoElement;
		ElementType erightchild = NoElement;
	
		if (ileft  <= nelements) eleftchild  = elements[ileft ];
		if (iright <= nelements) erightchild = elements[iright];

		// reverse the condition for minheap.
		if (!checklast && emax > eleftchild && emax > erightchild) break;

		if (eleftchild > erightchild && (!checklast || eleftchild > elast)) {	// left moves up
			//cout << eleftchild << " moving to " << elements[iparent] << ", iparent = " << ileft << " (from " << iparent << ")" << endl;
			elements[iparent] = eleftchild;
			iparent = ileft;
		} else if (eleftchild <= erightchild && (!checklast || erightchild > elast)) {	// right moves up.
			//cout << erightchild << " moving to " << elements[iparent] << ", iparent = " << iright << " (from " << iparent << ")" << endl;
			elements[iparent] = erightchild;
			iparent = iright;
		} else
			break;
	}

	return iparent;
}

ElementType Heap::deleteMax() {
	if (nelements == 0) return NoElement;	// sentinel.

	//cout << "deleting max...\n";
	ElementType emax = elements[1];
	ElementType elast = elements[nelements];
	int iparent = percolateDown(1);		// start from root.
	elements[iparent] = elast;
	--nelements;

	return emax;
}
int Heap::increaseKey(int ii, int delta) {
	if (ii > nelements) return 0;

	ElementType e = elements[ii] + delta;
	cout << "increasing key from " << elements[ii] << " to " << e << endl;
	elements[ii] = e;
	int newii = percolateUp(ii);
	elements[newii] = e;

	return newii;
}
int Heap::decreaseKey(int ii, int delta) {
	if (ii > nelements) return 0;

	ElementType e = elements[ii] - delta;
	cout << "decreasing key from " << elements[ii] << " to " << e << endl;
	if (e < 0) return 0;

	elements[ii] = e;
	int newii = percolateDown(ii, false);
	elements[newii] = e;

	return newii;
}
ElementType Heap::remove(int ii) {
	if (ii > nelements) return 0;

	cout << "removing " << elements[ii] << endl;
	increaseKey(ii, Infinity);
	return deleteMax();
}
void Heap::build(ElementType *input, int ninput, bool copy/* = true*/) {
	if (copy)
		for (int ii = 0; ii < ninput; ++ii)
			elements[ii + 1] = input[ii];
	nelements = ninput;

	for (int ii = nelements / 2; ii; --ii) {
		ElementType e = elements[ii];
		int newii = percolateDown(ii, false);
		//cout << "percolating down element " << e << " from index " << ii << " to " << newii << endl;
		elements[newii] = e;
		//print();
	}

}
bool Heap::isHeap(int ii) {	// checks for maxheap.
	if (ii <= nelements) {
		int iileft  = getLeft(ii);
		int iiright = getRight(ii);
		if (iileft  <= nelements && elements[ii] < elements[iileft])  return false;
		if (iiright <= nelements && elements[ii] < elements[iiright]) return false;
	}
	return true;
}
bool Heap::isHeap() {
	for (int ii = 1; ii <= nelements / 2; ++ii)
		if (!isHeap(ii)) return false;
	return true;
}
bool isPowerOf2(int nn) {
	return !(nn & (nn - 1));
}
void Heap::print() {
	for (int ii = 1; ii <= nelements; ++ii) {
		cout << "\t" << elements[ii];

		if (isPowerOf2(ii + 1)) cout << endl;
	}
	cout << endl;
}
void Heap::printArray(int asize) {
	cout << '[';
	for (int ii = 1; ii <= asize; ++ii)
		cout << elements[ii] << " ";
	cout << ']';
}
void Heap::hide_back(ElementType e) {
	elements[nelements + 1] = e;	// needs to be carefully used. Must have space (created using deleteMax).
}
int Heap::size() {
	return nelements;
}
