#include<iostream>
#include <vector>
#include <algorithm>
#include <stack>
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
    void printAllgreaterthanX(int x);
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
}
 void heap::printAllgreaterthanX(int x){
vector <int> max;
    stack <int> s;
    s.push(1);
    int temp;
    while(!s.empty()) {
        temp=s.top();s.pop();
        if(v[temp]>x) max.push_back(v[temp]);
        if(2*temp < v.size()) {
        if(v[2*temp]>x) s.push(2*temp);
        }
        if(2*temp+1 < v.size()) {
        if(v[2*temp+1]> x) s.push(2*temp+1);
        }
    }
    sort(max.begin(),max.end());
    for(int i=0;i<max.size();i++) {
        cout<<max[i]<<endl;;
    }
 }
int main(){
    int n,x;
    cin>>n>>x;
    heap h;
    vector <int> v;
    v.push_back(0);
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    h.build(v);
    h.v=v;
    h.printAllgreaterthanX(x);
    return 0;
}