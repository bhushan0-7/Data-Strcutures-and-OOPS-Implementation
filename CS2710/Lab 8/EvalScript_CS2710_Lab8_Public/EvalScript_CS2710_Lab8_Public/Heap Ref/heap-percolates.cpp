#include "heap-percolates.hpp"
using namespace std; 

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
}


