#include <iostream>
#include <vector>
#include <sys/time.h>
#include <stdlib.h>
#include "heap.h"

using namespace std;

// compile as g++ heap-sort.cpp heap.cpp
int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <N>\n";
		return 1;
	}
	
	int nelements = atoi(argv[1]);	// TODO: no checks on nelements.

	Heap h;
	ElementType *elements = new ElementType[nelements];

	srand(time(NULL));

	for (int ii = 0; ii < nelements; ++ii)
		h.insert(rand() % 50);

	h.print();
	cout << "The tree is " << (h.isHeap() ? "" : "NOT ") << "a heap.\n";
	h.printArray(nelements);

	for (int ii = 0; ii < nelements; ++ii) {
		h.hide_back(h.deleteMax());
	}
	h.printArray(nelements);

	return 0;
}
