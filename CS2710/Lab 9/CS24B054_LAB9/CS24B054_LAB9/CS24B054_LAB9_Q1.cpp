#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class hashtable{
  public:
  int a=503,b=1087,p=2003;
   vector<vector<int>> v= vector<vector<int>> (2003);
  bool search(int key);
  void insert(int key);
  void Delete(int key);
  void print();
};
bool hashtable::search(int key){
    int x=(a*key+b)%p;
    for(int i=0;i<v[x].size();i++) {
        if(v[x][i]==key) return true;
    }
    return false;
}
void hashtable::insert(int key) {
   int x=(a*key+b)%p;
   v[x].push_back(key);
   sort(v[x].begin(),v[x].end());
}
void hashtable::Delete(int key) {
     int x=(a*key+b)%p;
     for(int i=0;i<v[x].size();i++) {
        if(v[x][i]==key) v[x].erase(v[x].begin()+i);
     }
}
void hashtable::print(){
    for(int i=0;i<2003;i++) {
       if(!v[i].empty()) {
        cout<<i<<" ";
        for(int j=v[i].size()-1;j>=0;j--) {
          cout<<v[i][j]<<" ";
        }
        cout<<endl;
       }
    }
}
int main() {
    int n;
    cin>>n;
    hashtable h;
    while(n--) {
        string temp;
        cin>>temp;
        if(temp=="Insert") {
            int x;
            cin>>x;
            if(!h.search(x)) h.insert(x);
        }
        if(temp=="Search") {
            int x;
            cin>>x;
            if(h.search( x)) cout<<"TRUE"<<endl;
            else cout<<"FALSE"<<endl;
        }
        if(temp=="Delete") {
            int x;
            cin>>x;
            h.Delete(x);
        }
    }
    h.print();
}