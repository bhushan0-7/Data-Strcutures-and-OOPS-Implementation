#include <iostream>
using namespace std;
template <typename T>
int linearSearch(T* arr, int size, T key){
    if(size==0) return -1;
    for(int i=0;i<size;i++) {
        if(arr[i]==key) return i;
    }
    return -1;
}
template <typename T>
int binarySearch(T* arr, int size, T key){
    int low=0,high=size-1;
    int index=0,flag=0;
    while(low<=high && high>=0 && low<size) {
        int mid=(low+high)/2;
        if(arr[mid] == key) {
            index=mid;
            flag=1;
            break;
        }
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    while(index>=0 && arr[index]==key) index--;
    if(flag==1) return index+1;
    return -1;
}
template <typename T>
void sort(T* arr, int size){
    for(int i=0;i<size-1;i++) {
        for(int j=0;j<size-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                T temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
template <typename T>
class MagicalCrate{
private:
    T* container;
    int size=0;
    int capacity=2;
public:
    MagicalCrate(){
        container=new T[capacity];
    }
    void add(T item);
    T remove();
    int find(T item){
        return linearSearch(container,size,item);
    }
    void printSize(){
        cout<<"Size: "<<size<<endl;
    }
    void printCapacity(){
        cout<<"Capacity: "<<capacity<<endl;
    }
    void print(){
        for(int i=0;i<size;i++) {
            cout<<container[i]<<" ";
        }
        cout<<endl;
    }
};
template <typename T>
void MagicalCrate<T>::add(T item) {
    if(size==capacity/2) {
        capacity*=2;
       T* temp=container;
       container=new T[capacity];
       for(int i=0;i<size;i++) {
         container[i]=temp[i];
       }
       delete temp;
    }
    container[size++]=item;
}
template <typename T>
T MagicalCrate<T>::remove(){
    if(size==0) {
        cout<<"Error: Crate is empty"<<endl;
        return -1;
    }
    T max=container[0];
    for(int i=1;i<size;i++) {
        if(max<container[i]) max=container[i];
    }
    int index=0;
    while(container[index]!=max) index++;
    for(int i=index+1;i<size;i++) {
        container[i-1]=container[i];
    }
    size--;
    if(size < capacity/4 && capacity >=4){
        capacity=capacity/2;
        T* temp=container;
        container=new T[capacity];
        for(int i=0;i<size;i++) {
            container[i]=temp[i];
        }
        delete temp;
    }
    return max;
}
int main(){
    string s;
    cin>>s;
    if(s=="global") {
        int* array;
        double* nums;
        string type;
        cin>>type;
        int n;cin>>n;
        if(type=="int") {
            array=new int[n];
            for(int i=0;i<n;i++) cin>>array[i];
        }
        else {
            nums=new double(n);
            for(int i=0;i<n;i++) cin>>nums[i];
        }
        int k;
        cin>>k;
        while(k--) {
            string s;
            cin>>s;
            if(s=="linearSearch") {
                if(type=="int") {
                     int val;cin>>val;
                    cout<<linearSearch(array,n,val)<<endl;
                }
                else{
                    double val;cin>>val;
                    cout<<linearSearch(nums,n,val)<<endl;
                }
            }
            else if(s=="binarySearch") {
                if(type=="int") {
                     int val;cin>>val;
                    cout<<binarySearch(array,n,val)<<endl;
                }
                else{
                    double val;cin>>val;
                    cout<<binarySearch(nums,n,val)<<endl;
                }
            }
            else {
                if(type=="int") sort(array,n);
                else sort(nums,n);
                cout<<"Sorted"<<endl;
            }
        }
    }
    else {
      if(s=="int") {
        MagicalCrate <int> M;
        string temp;
        while(cin>>temp) {
            if(temp=="add") {
                int val;
                cin>>val;
                M.add(val);
            }
            else if(temp=="remove") {
                int t=M.remove();
                if(t!=-1) cout<<t<<endl;
            }
            else if(temp=="find") {
                int val;
                cin>>val;
                cout<<M.find(val)<<endl;
            }
            else if(temp=="size") M.printSize();
            else if(temp=="capacity") M.printCapacity();
            else M.print();
        }
      }
      else {
        MagicalCrate <double> M;
        string temp;
        while(cin>>temp) {
            if(temp=="add") {
                double val;
                cin>>val;
                M.add(val);
            }
            else if(temp=="remove") {
                double t=M.remove();
                if(t!=-1) cout<<t<<endl;
            }
            else if(temp=="find") {
                double val;
                cin>>val;
                cout<<M.find(val)<<endl;
            }
            else if(temp=="size") M.printSize();
            else if(temp=="capacity") M.printCapacity();
            else M.print();
        }
      }
    }
    return 0;
}
