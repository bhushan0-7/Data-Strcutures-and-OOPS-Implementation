#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class graph{
    public:
    int n;
    vector<int> visited;
    vector<vector<int>> v;
    graph(int n) {
    this->n=n;
     visited=vector <int> (n);
     v= vector<vector<int>> (n);
    }
};
int main() {
    int cities;
    cin>>cities;
    graph g(cities);
    int m;
    cin>>m;
    int start;
    cin>>start;
    for(int i=0;i<m;i++) {
       int x,y;
       cin>>x>>y;
       (g.v[x]).push_back(y);
       (g.v[y]).push_back(x);
    }
    queue <int> q;
    int count=0;
     q.push(start);
     g.visited[start]=1;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        count++;
        for(int i=0;i<g.v[x].size();i++) {
       if(g.visited[g.v[x][i]]==0) {
        q.push(g.v[x][i]);
       g.visited[g.v[x][i]]=1;
       }
    }
    }
    if(count==cities) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
