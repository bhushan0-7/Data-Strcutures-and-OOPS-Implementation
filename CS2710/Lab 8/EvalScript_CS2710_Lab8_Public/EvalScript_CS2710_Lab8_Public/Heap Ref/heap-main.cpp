#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include "heap.h"

using namespace std;

// compile as g++ heap-main.cpp heap.cpp
int main() {
	Heap h;
	ElementType elements[] = {39, 30, 12, 6, 29, 5, 11, 3, 1};
	//ElementType elements[] = {1, 3, 5, 6, 11, 12, 29, 30, 39}; 
	//ElementType elements[] = {39, 30, 31, 15, 29, 6, 3, 4, 7};
	int nelements = sizeof(elements) / sizeof(*elements);

	/*for (int ii = 0; ii < nelements; ++ii)
		h.insert(elements[ii]);
	*/
	h.build(elements, nelements);
	h.print();
	cout << "The tree is " << (h.isHeap() ? "" : "NOT ") << "a heap.\n";

	/*for (int ii = 0; ii < nelements; ++ii) {
		cout << "Deleted " << h.deleteMax() << endl;
		h.print();
		cout << "The tree is " << (h.isHeap() ? "" : "NOT ") << "a heap.\n";
	}*/
	srand(time(NULL));
	for (int ii = 0; ii < 10; ++ii) {
		int delta = rand() % 20;
		int index = rand() % nelements + 1;
		if (delta % 5 == 0) h.increaseKey(index, delta);
		else if (delta % 5 == 1) h.decreaseKey(index, delta);
		else if (delta % 5 == 2) h.deleteMax();
		else if (delta % 5 == 3) h.remove(index);
		else h.insert(elements[index] + delta);
		h.print();
		cout << "The tree is " << (h.isHeap() ? "" : "NOT ") << "a heap.\n";
	}
	return 0;
}
