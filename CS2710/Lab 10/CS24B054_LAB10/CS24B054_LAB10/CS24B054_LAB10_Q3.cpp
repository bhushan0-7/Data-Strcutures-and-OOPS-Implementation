#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class graph{
    public:
    int n;
    vector<int> visited;
    vector<vector<int>> v;
    vector<int> indegree;
    vector<int> label;
    graph(int n) {
    this->n=n;
     visited=vector <int> (n);
     v=vector<vector<int>> (n);
     indegree=vector <int> (n);
     label=vector <int> (n);
    }
    void toposort();
};
void graph::toposort(){
    queue <int> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            indegree[i]+=v[j][i];
        }
        if(indegree[i]==0) {
            q.push(i);
            label[i]=1;
            visited[i]=1;
        }
    }
    int flag=0;
    while(!q.empty()){
        int temp=q.front();q.pop();
        for(int i=0;i<n;i++) {
            if(v[temp][i]==1) {
               v[temp][i]=0;
               indegree[i]--;
               if(indegree[i]==0) {
                q.push(i);
                visited[i]=1;
                label[i]=label[temp]+1;
            }
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(visited[i]==0) flag=1;
    }
    if(flag==0) {
    for(int i=0;i<n;i++) {
        cout<<i<<" "<<label[i]<<endl;
    }
}
else {
    cout<<"Cycle"<<endl;
}
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
    }
    queue <int> q;
     vector <int> label(n);
    vector <int> indegree(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            indegree[i]+=g.v[j][i];
        }
        if(indegree[i]==0) {
            q.push(i);
            label[i]=1;
            g.visited[i]=1;
        }
    }
    int flag=0;
    while(!q.empty()){
        int temp=q.front();q.pop();
        for(int i=0;i<n;i++) {
            if(g.v[temp][i]==1) {
               g.v[temp][i]=0;
               indegree[i]--;
               if(indegree[i]==0) {
                q.push(i);
                g.visited[i]=1;
                label[i]=label[temp]+1;
            }
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(g.visited[i]==0) flag=1;
    }
    if(flag==0) {
    for(int i=0;i<n;i++) {
        cout<<i<<" "<<label[i]<<endl;
    }
}
else {
    cout<<"Cycle"<<endl;
}
}