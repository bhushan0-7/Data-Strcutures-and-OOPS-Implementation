#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class graph{
    public:
    int n;
    int time=1;
    int flag=0;
    vector<int> visited;
    vector <int> arrival;
    vector <int> parent;
    vector <int> departure;
    vector <int> bridge;
    vector<vector<int>> v;
    graph(int n) {
    this->n=n;
     visited=vector <int> (n);
     v= vector<vector<int>> (n);
     arrival=vector<int> (n);
     departure=vector<int> (n);
     parent=vector<int> (n);
     bridge=vector<int> (n);
     for(int i=0;i<n;i++) {
        parent[i]=-1;
        bridge[i]=-1;
     }
    }
    int edge2(int x);
};
int graph::edge2(int x) {
   visited[x]=1;
   arrival[x]=time++;
   int deepest=arrival[x];
   int temp;
   for(int i=0;i<n;i++) {
    if(v[x][i]==1 && i !=parent[x]) {
        if(visited[i]!=1) {
            parent[i]=x;
            temp=edge2(i);
        }
    else temp=arrival[i];
    deepest=min(deepest,temp);
    }
   }
   departure[x]=time++;
   if(parent[x]!=-1 && arrival[x]==deepest) {
    bridge[x]=parent[x];
    flag=1;
   }
   return deepest;   
}
int main() {
   int n,m;
   cin>>n>>m;
   graph g(n);
   for(int i=0;i<n;i++) {
    g.v[i].resize(n);
   }
   for(int i=0;i<m;i++) {
       int x,y;
       cin>>x>>y;
        g.v[x][y]=1;
        g.v[y][x]=1;
    }
    g.edge2(0);
    if(g.flag==1) {
        cout<<"no"<<endl;
        for(int i=0;i<g.bridge.size();i++) {
            if(g.bridge[i]!=-1) {
                cout<<g.bridge[i]<<" "<<i<<endl;
            }
        }
    }
    else cout<<"yes"<<endl;

}