#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// define the class MyArray with the given members. 
class MyArray{
private:
 int *arr;
 int length;
 //defining arr pointer and length as private members.
 public:
 // default constructor that initialises array to null pointer.
 MyArray(){
    arr=NULL;
    length=0;
 }
// constructor that creates array of size n and initialises each element to 0.
 MyArray(int n){
    length=n;
    arr=(int*)malloc(sizeof(int)*n); //dynamic allocation of memory
    for(int i=0;i<n;i++) arr[i]=0;
 }
 //constructor that creates array of size n and initialises each element to a.
 MyArray(int n ,int a){
    length=n;
     arr=(int*)malloc(sizeof(int)*n); //dynamic allocation of memory
    for(int i=0;i<n;i++) arr[i]=a;
 }
 void InsertAt(int index,int value); // inserts value at the given index.
 bool empty();// checks whether the array is empty or not
 int at(int index);//return the value present at given index
 int size(); // returns size of the array
 bool IsSorted(); //checks whether the array is sorted or not
 bool PairSumEqualTo(int k); // checks whether there exists two indices such that their corresponding array elements sum is equal to k
 int & operator[](int index);// returns a reference to the array element
};
void MyArray::InsertAt(int index,int value){
    int *arr1=(int*)malloc(sizeof(int)*(length+1));
    for(int i=0;i<index;i++) arr1[i]=arr[i];
    arr1[index]=value;
    for(int i=index+1;i<=length;i++) arr1[i]=arr[i-1];
    length=length+1;
    arr=arr1;
}
bool MyArray::empty(){
    if(arr==NULL) return true;
    else return false;
    // checks whether array is empty and if yes returns true
}
int MyArray::at(int index){
    if(index<length) {
        return arr[index];
    }
    return arr[index];
    //returns value of the array element present at index. 
}
int MyArray::size() {
    return length;
    // returns size of the array
}
bool MyArray::IsSorted(){
for(int i=0;i<length-1;i++) {
    if(arr[i]>arr[i+1]) return false; // checks the array is sorted or not
}
return true; // returns true if sorted
}
bool MyArray::PairSumEqualTo(int k) {
    sort(arr,arr+length);
    int start=0,end=length-1; 
    // assigning two variable one to the start and other to the end of the array.
    while(start<end){
        if(arr[start]+arr[end]==k) return true;
        else if(arr[start]+arr[end]>k) end--; // if elements sum is greater than k we need to decrease sum.so,end--
        else start++;// to increase sum, start++;
    }
   return false; // returns true if there are two indices satisfying given condition
}
int&  MyArray::operator[](int index) {
    return *(arr+index); // returning a reference to the array element present at index i.

} 
int main(){
      int n;
      cin>>n;
      // taking size of array as input
      MyArray num(n);
      //declaring a object of MyArray class
      for(int i=0;i<n;i++) {
        int value;
        cin>>value;
        num[i]=value;
        //taking array elements as input
      }
      int k; // k represents target sum
      cin>>k;
      // taking target sum as input
      if(num.PairSumEqualTo(k)==true) cout<<"Yes"<<endl; // prints yes if target sum can be acheived or else prints no
      else cout<<"No"<<endl;   

}