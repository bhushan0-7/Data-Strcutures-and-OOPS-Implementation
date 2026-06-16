#include<iostream>
#include <vector>
using namespace std;
class heap{
    public:
    vector <int> v;
    int size=1;
    void insert(int x);
    void DeleteMax();
    int maximum();
    void build(vector <int> &v);
    void percolateup(int i);
    void percolatedown(int i);
    void print();
};
void heap::print(){
    for(int i=1;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int heap::maximum() {
    if(v.size()!=1) return v[1];
    return 0;
}
void heap::percolateup(int i) {
    while(i>1) {
        if(v[i] > v[(i)/2]) {
            swap(v[i],v[(i)/2]);
            i=(i)/2;
        }
        else break;
    }
    return;
}
void heap::insert(int x){
    v.push_back(x);
    size++;
    this->percolateup(v.size()-1);
}
void heap::percolatedown(int i) {
    while(2*i<v.size()) {
        if(2*i+1 < v.size()) {
            int index=2*i+1;
            if(v[index] < v[2*i]) index=2*i;
            if(v[i]< v[index]) {
            swap(v[i],v[index]);
            i=index;
            }
            else break;
        }
        else {
           if(v[i]<v[2*i]) {
            swap(v[i],v[2*i]);
            i=2*i;
           }
           else break;
        }
    }
    return;
}
void heap::DeleteMax(){
    swap(v[1],v[v.size()-1]);
    v.pop_back();
    size--;
   this->percolatedown(1);
}
void percolate(int i,vector <int> &v) {
    while(2*i<v.size()) {
        if(2*i+1 < v.size()) {
            int index=2*i+1;
            if(v[index] < v[2*i]) index=2*i;
            if(v[i]< v[index]) {
            swap(v[i],v[index]);
            i=index;
            }
            else break;
        }
        else {
           if(v[i]<v[2*i]) {
            swap(v[i],v[2*i]);
            i=2*i;
           }
           else break;
        }
    }
    return;
}
void heap::build(vector <int> &v) {
    for(int i=v.size()/2;i>=1;i--) {
        percolate(i,v);
    }
    this->v=v;
}
int main(){
    int n,k;
    cin>>n>>k;
    heap h;
    vector <int> v(n+1);
    for(int i=1;i<n+1;i++) cin>>v[i];
    h.build(v);
    for(int i=0;i<k;i++) {
        cout<<h.maximum()<<" ";
        h.DeleteMax();
    }
    cout<<endl;
    return 0;
}
