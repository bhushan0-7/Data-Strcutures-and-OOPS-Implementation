#include <iostream>
using namespace std;
class WarehouseFull{};
class Overloaded{};
class Powererr{};
class Empty{};
template <typename T>
class Box{
    public:
    T data;
    int weight;
};

template <typename T>
class Storage{
public:
int count;
Box<T> *ptr;
Storage(){  
}
Storage(int cap) {
 ptr=new Box[cap];
 count=0;
}
void push(T item, int weight){
    Box<T> temp;
    temp.data=item;
    temp.weight=weight;
    ptr[count]=temp;
    count++;
}
Box<T> pop(){
    count--;
    return ptr[count];
}
int currentSize(){
    return count;
}
};

template <typename T>
class WareHouse{
public:
Storage <T> s;
int maxcapacity;
int maxweight;
int currenergy;
int currweight;
WareHouse(int cap,int w,int e):s(){
    s.ptr=new Box<T>[cap];
    s.count=0;
    maxcapacity=cap;
    maxweight=w;
    currenergy=e;
    currweight=0;
}
void receive(T data,int weight){
  if(maxcapacity==s.count) throw WarehouseFull();
  if(currweight+weight > maxweight) throw Overloaded();
  currweight+=weight;
  s.push(data,weight);
  return;
}
Box<T> popSingle(){
  if(currenergy < 2) throw Powererr();
  if(s.count==0) throw Empty();
  Box temp= s.pop();
  currenergy-=2;
  currweight-=temp.weight;
  return temp;
}
void popBulk(int k){
   if(currenergy < 2) throw Powererr();
   if(s.count==0) throw Empty();
    int ene=currenergy;
    int c=s.count;
    int t=k;
    while(t--) {
        if(ene < 2) throw Powererr();
        if(c==0) throw Empty();
        ene-=2;
        c--;
        t--;
    }
    while(k--) {
        Box<T> t=s.pop();
        currenergy-=2;
        currweight-=t.weight;
        cout<<t.data<<endl;
    }
    return;
}
void RechargeEnergy(int val) {
    currenergy+=val;
}
};
int main(){
    int cap,wei,ene;cin>>cap>>wei>>ene;
    char type;cin>>type;
    int n;
    cin>>n;
    if(type=='I') {
        WareHouse <int> w(cap,wei,ene);
        while(n--) {
            try{
            int v;
            cin>>v;
            if(v==1){
                int data,weight;
                cin>>data>>weight;
                w.receive(data,weight);
            }
            else if (v==2){
                Box<int> t =w.popSingle();
                cout<<t.data<<endl;
            }
            else if(v==3){
                 int val;cin>>val;
                 w.RechargeEnergy(val);
            }
            else {
                int k;cin>>k;
                // w.popBulk(k);
            }
    }
    catch(WarehouseFull &f){
        cout<<"ERR_FULL"<<endl;
    }
    catch(Empty &e){
        cout<<"ERR_EMPTY"<<endl;
    }
    catch(Powererr &e){
        cout<<"ERR_POWER"<<endl;
    }
    catch(Overloaded &e){
        cout<<"ERR_WEIGHT"<<endl;
    }
    }
    }
     else if(type=='C') {
        WareHouse <char> w(cap,wei,ene);
        while(n--) {
            try{
            int v;
            cin>>v;
            if(v==1){
                char data;int weight;
                cin>>data>>weight;
                w.receive(data,weight);
            }
            else if (v==2){
                Box<char> t =w.popSingle();
                cout<<t.data<<endl;
            }
            else if(v==3){
                 int val;cin>>val;
                 w.RechargeEnergy(val);
            }
            else {
                int k;cin>>k;
                // w.popBulk( k);
            }
    }
    catch(WarehouseFull &f){
        cout<<"ERR_FULL"<<endl;
    }
    catch(Empty &e){
        cout<<"ERR_EMPTY"<<endl;
    }
    catch(Powererr &e){
        cout<<"ERR_POWER"<<endl;
    }
    catch(Overloaded &e){
        cout<<"ERR_WEIGHT"<<endl;
    }
    }
    }
    else if(type=='F') {
        WareHouse <float> w(cap,wei,ene);
        while(n--) {
            try{
            int v;
            cin>>v;
            if(v==1){
                float data;int weight;
                cin>>data>>weight;
                w.receive(data,weight);
            }
            else if (v==2){
                Box<float> t =w.popSingle();
                cout<<t.data<<endl;
            }
            else if(v==3){
                 int val;cin>>val;
                 w.RechargeEnergy(val);
            }
            else {
                int k;cin>>k;
                // w.popBulk( k);
            }
    }
    catch(WarehouseFull &f){
        cout<<"ERR_FULL"<<endl;
    }
    catch(Empty &e){
        cout<<"ERR_EMPTY"<<endl;
    }
    catch(Powererr &e){
        cout<<"ERR_POWER"<<endl;
    }
    catch(Overloaded &e){
        cout<<"ERR_WEIGHT"<<endl;
    }
    }
    }
    return 0;
}
