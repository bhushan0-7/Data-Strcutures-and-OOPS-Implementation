#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include "heap.h"

using namespace std;

// compile as g++ heap-kmax.cpp heap.cpp
int main(int argc, char *argv[]) {
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " <N> <K>\n";
		return 1;
	}
	
	int nelements = atoi(argv[1]);
	int k = atoi(argv[2]);

	if (k > nelements) {	// I am not checking if k and n are positive.
		cerr << "Error: k in max-k is greater than the number of elements (" << k << " > " << nelements << ")" << endl;
		return 1;
	}
	Heap h;
	ElementType *elements = new ElementType[nelements];

	srand(time(NULL));

	for (int ii = 0; ii < nelements; ++ii)
		h.insert(rand() % 50);

	h.print();
	cout << "The tree is " << (h.isHeap() ? "" : "NOT ") << "a heap.\n";

	for (int ii = 0; ii < k - 1; ++ii)
		h.deleteMax();
	cout << k << "'th largest element is " << h.deleteMax() << endl;

	return 0;
}
