#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class hashtable{
  public:
  int a=503,b=1087,p=2003;
   vector<int> v=vector<int> (2003);
   hashtable(){
    for(int i=0;i<v.size();i++) {
        v[i]=-1;
    }
   }
  bool search(int key,string method);
  int nextquad(int key);
  int nextdouble(int key);
  void insert(int key,string method);
  void Delete(int key,string method);
  void print();
};
int hashtable::nextquad(int key) {
    int x=(a*key+b)%p;
    int temp=x;
    int i=0;
    while(v[temp]>=0) {
      temp=(x+i*i)%p;
      i++;
    }
    return temp;
}
int hashtable::nextdouble(int key) {
    int temp;
    if(v[key%61]<0) return key%61;
    else {
         temp=key%61;
        int j=1;
        while(v[temp]>=0) {
           temp=((key%61)+j*((key*key+1)%61))%p;
            j++;
        }
    }
    return temp;
}
bool hashtable::search(int key,string method){
     if(method=="Quad") {
        int x=(a*key+b)%p;
    int temp=x;
    int i=0;
    while(v[temp]!=-1 && v[temp]!=key) {
      temp=(x+i*i)%p;
      i++;
    }
    if(v[temp]==key) return true;
     } 
     else {
        int temp;
    if(v[key%61]==-1) return false;
    else {
         temp=key%61;
        int j=1;
        while(v[temp]!=-1 && v[temp]!=key) {
            temp=((key%61)+j*((key*key+1)%61))%p;
            j++;
        }
        if(v[temp]==key) return true;
    }
     }
   return false;
}
void hashtable::insert(int key,string method) {
   if(method=="Quad") {
     int temp=nextquad(key);
     v[temp]=key;
   }
   else {
    int temp=nextdouble(key);
    v[temp]=key;
   }
}
void hashtable::Delete(int key,string method) {
     if(method=="Quad") {
        int x=(a*key+b)%p;
    int temp=x;
    int i=0;
    while(v[temp]!=-1 && v[temp]!=key) {
      temp=(x+i*i)%p;
      i++;
    }
    if(v[temp]==key) v[temp]=-2;
     }
     else {
        int temp;
    if(v[key%61]==-1) return;
    else {
         temp=key%61;
        int j=1;
        while(v[temp]!=-1 && v[temp]!=key) {
           temp=((key%61)+j*((key*key+1)%61))%p;
            j++;
        }
        if(v[temp]==key)  v[temp]=-2;
    }
     }
   return;
}
void hashtable::print(){
   for(int i=0;i<v.size();i++) {
    if(v[i]>=0) {
        cout<<i<<" "<<v[i]<<endl;
    }
   }
}
int main() {
    int n;
    cin>>n;
    string method;
    cin>>method;
    hashtable h;
    while(n--) {
        string temp;
        cin>>temp;
        if(temp=="Insert") {
            int x;
            cin>>x;
            if(!h.search(x,method)) h.insert(x,method);
        }
        if(temp=="Search") {
            int x;
            cin>>x;
            if(h.search(x,method)) cout<<"TRUE"<<endl;
            else cout<<"FALSE"<<endl;
        }
        if(temp=="Delete") {
            int x;
            cin>>x;
            h.Delete(x,method);
        }
    }
    h.print();
}
