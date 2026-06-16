typedef int ElementType;

class Heap {
public:
	Heap(int maxN = 20, ElementType *ele = NULL);
	int insert(ElementType e);
	ElementType deleteMax();
	void print();
	int size();

	int increaseKey(int ii, int delta);		// cannot give key value, since search is costly.
	int decreaseKey(int ii, int delta);
	ElementType remove(int ii);
	void build(ElementType *input, int ninput, bool copy = true);
	bool isHeap();
	bool isHeap(int ii);

	// for heap sort.
	void printArray(int);
	void hide_back(ElementType);

private:
	int nelements, maxN;
	ElementType *elements;				// assumes unique elements.

	int percolateUp(int ii);
	int percolateDown(int ii, bool checklast = true);
	int getParent(int ii) { return ii / 2; }
	int getLeft(int ii) { return 2 * ii; }
	int getRight(int ii) { return 2 * ii + 1; }

	static const ElementType NoElement = -999999;	// heap elements must be non-negative.
	static const ElementType Infinity = 999999;
};


