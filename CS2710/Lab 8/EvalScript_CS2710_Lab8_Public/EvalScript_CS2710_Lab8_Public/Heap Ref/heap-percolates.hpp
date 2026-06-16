/* 
 * Binary MaxHeap, with insert (enqeueue) and deleteMax (dequeue)
 * operations.  
 * Implemented using an array with 1-based indexing, and two
 * primitive opns.: percolateUp(hole) and percolateDown(hole). 
 */ 
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std; 

typedef int ElementType; 
static const ElementType invalidElem = -1; 

class MaxHeap
{
  public: 
    MaxHeap(int maxN=10) : arr(maxN), cursize(0) {  }
    MaxHeap(const vector<ElementType> &inpArr) {  buildHeap(inpArr);  }

    bool isEmpty() {  return (cursize==0);  }
    bool isFull() {  return ((cursize+1)==arr.size());  } //+1 for the unused arr[0]
    void insert(ElementType e); 
    ElementType findMax(); 
    ElementType deleteMax(); 

    /* Exercise: implement these functions! */ 
    void decreaseKey(int idx, ElementType delta)
    {
      assert(idx >= 1 && idx <= cursize); 
      //Exercise
    }
    void increaseKey(int idx, ElementType delta)
    {
      assert(idx >= 1 && idx <= cursize); 
      //Exercise
    }
    void remove(int idx)
    {
      assert(idx >= 1 && idx <= cursize); 
      //Exercise
    }

    void buildHeap(const vector<ElementType> &inpArr)
    {
      cursize = inpArr.size(); 
      arr.resize(cursize+1); 
      for (int i=0; i < cursize; i++) {  arr[i+1] = inpArr[i];  }

      //no need to percolate down any leaves, so percolate down all
      //other internal nodes from last to first index. 
      for (int i = cursize/2; i > 0; i--) 
      {
        percolateDown(i); 
      }
    }

    void print()
    {
      cout << "---MaxHeap " << cursize << " elems out of max " << arr.size()-1 << " stored:\n"; 
      int lev = 0; 
      for (int i=1; i <= cursize; i++) 
      {
        cout << arr[i] << " "; 
        //cout << "DBG:" << (pow(2,lev+1)-1) << endl; 
        if (i==(pow(2,lev+1)-1))
        {
          lev++; 
          cout << endl; 
        } 
      }
      cout << "---" << endl; 
    }

  private: 
    vector<ElementType> arr; 
    int cursize; //# of elems currently stored in heap

    //two primitive operations central to implementing all
    //functionalities of the heap!
    void percolateUp(int hole); 
    void percolateDown(int hole); 
}; 
 
void MaxHeap::insert(ElementType e)
{
  if (isFull()) {  arr.resize(2*arr.size() + 1);  }
  int hole = cursize+1; 
  arr[hole] = e; //put e into last available locn and percolate up
  cursize++; 
  percolateUp(hole); //fix heap-order property (structural property already satisfied)
  return; 
}

ElementType MaxHeap::findMax()
{
  if (isEmpty()) {  cerr << "Warning: MaxHeap empty!\n"; return invalidElem;  }
  return arr[1];  //return the root elem, which is max elmt in MaxHeap
}

ElementType MaxHeap::deleteMax()
{
  if (isEmpty()) {  cerr << "Warning: MaxHeap empty!\n"; return invalidElem;  }
  
  ElementType retval = arr[1]; 
  int hole = 1; 
  arr[hole] = arr[cursize];  //put last elem into hole & percolate down! 
  cursize--; 
  percolateDown(hole); //fix heap-order property (structural property already satisfied)
  return retval; 
}

//move a hole upwards in the tree until the heap order property gets satisfied!
//fixes heap-order property (structural property already satisfied)
void MaxHeap::percolateUp(int hole)
{
  if (isEmpty())  return; 
  assert(hole >= 1 && hole <= cursize); 
  ElementType e = arr[hole]; 
  while (hole > 1             //hole has a parent?
         && arr[hole/2] < e)  //heap-order property false?
  {
    arr[hole] = arr[hole/2]; //move parent (hole/2) value into hole, so that... 
    hole = hole/2; //...hole can be percolated up by one unit!
  }
  arr[hole] = e;  //e finally stored into correct locn
  return; 
} 

//move a hole downwards in the tree until the heap order property gets satisfied!
//fixes heap-order property (structural property already satisfied)
void MaxHeap::percolateDown(int hole)
{
  if (isEmpty()) {  return;  }
  assert(hole >= 1 && hole <= cursize); 
  ElementType e = arr[hole]; 
  while ((2*hole) <= cursize) //hole has a child?  
  {
    //childmax holds index of the larger-valued child
    int child1 = 2*hole;  int child2 = 2*hole+1; 
    int childmax = child1; 
    if (child2 <= cursize && arr[child2] > arr[child1]) 
    { 
      childmax = child2; 
    } 

    if (arr[childmax] < e) //heap-order true?
    { 
      break; //nothing more to fix!
    } 
    arr[hole] = arr[childmax]; //move larger child's value into hole. so that... 
    hole = childmax; //...hole can be percolated down by one unit!
  }
  arr[hole] = e;  //e finally stored into correct locn
  return; 
}

/* //this main fn has now been moved to heap-percolates.cpp 
int main()
{
  MaxHeap mh; 
  mh.print(); 
  mh.insert(1); 
  mh.insert(100); 
  mh.print(); 
  for (int i=2; i < 100; i++) 
  {
    mh.insert(i); 
  }
  mh.print(); 
  cout << mh.findMax() << endl; 
  while (!mh.isEmpty())
  { 
    cout << mh.deleteMax() << " "; 
  } 
  cout << endl; 
  return 0; 
} */


