#include<iostream>
#include <vector>
using namespace std;
class heap{
    public:
    vector <int> v;
    int size=0;
    void insert(int x);
    void DeleteMax();
    int maximum();
    void build(vector <int> &v);
    void percolateup(int i);
    void percolatedown(int i);
    void print();
};
void heap::print(){
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int heap::maximum() {
    if(size!=0) return v[0];
    return 0;
}
void heap::percolateup(int i) {
    while(i>0) {
        if(v[i] > v[(i-1)/3]) {
            swap(v[i],v[(i-1)/3]);
            i=(i-1)/3;
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
    while(3*i+1<v.size()) {
        if(3*i+3<v.size()) {
            int index=3*i+3;
            if(v[index] < v[3*i+2]) index=3*i+2;
            if(v[index] < v[3*i+1]) index=3*i+1;
            if(v[index]> v[i]) {
                swap(v[i],v[index]);
                i=index;
            }
            else break;
        }
        else if(3*i+2<v.size()) {
             int index=3*i+2;
             if(v[index] < v[3*i+1]) index=3*i+1;
             if(v[index]> v[i]) {
                swap(v[i],v[index]);
                i=index;
             }
             else break;
        }
        else {
            if(v[3*i+1] > v[i]) {
                swap(v[i],v[3*i+1]);
                i=3*i+1;
            }
            else break;
        }
    }
    return;
}
void heap::DeleteMax(){
    swap(v[0],v[size-1]);
    v.pop_back();
    size--;
   this->percolatedown(0);
}
void percolate(int i,vector <int> &v) {
    while(3*i+1<v.size()) {
        if(3*i+3<v.size()) {
            int index=3*i+3;
            if(v[index] < v[3*i+2]) index=3*i+2;
            if(v[index] < v[3*i+1]) index=3*i+1;
            if(v[index] > v[i]) {
                swap(v[i],v[index]);
                i=index;
            }
            else break;
        }
        else if(3*i+2<v.size()) {
             int index=3*i+2;
             if(v[index] < v[3*i+1]) index=3*i+1;
             if(v[index]> v[i]) {
                swap(v[i],v[index]);
                i=index;
             }
             else break;
        }
        else {
            if(v[3*i+1] > v[i]) {
                swap(v[i],v[3*i+1]);
                i=3*i+1;
            }
            else break;
        }
    }
    return;
}
void heap::build(vector <int> &v) {
    for(int i=v.size()/2;i>=0;i--) {
        percolate(i,v);
    }
    this->v=v;
}
int main(){
    int n;
    cin>>n;
    heap h;
    while (n--) {
       string temp;
       cin>>temp;
       if(temp=="Maximum") {
          if(h.size==0) cout<<"Empty"<<endl;
          else cout<<h.maximum()<<endl;
       }
       if(temp=="Insert") {
        int x;
        cin>>x;
        h.insert(x);
       }
       if(temp=="DeleteMax") {
        if(h.size!=0)
        h.DeleteMax();
       }
    }
    return 0;
}
