#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[n];
    string query;
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s,s+n);
     cin>>query;
    string temp;
    int start=0,end=0;
    for(size_t i=0;i<query.size();i++){
        temp.push_back(query[i]);
        for(int j=start;j<n;j++) {
        if(temp>s[j]) start++;
        else break;
        }
       end = start;
       for(int k=start;k<n;k++) {
        if(temp<=s[k]) {
            int flag=0;
            for(size_t j=0;j<temp.size();j++){
                if(temp[j]!=s[k][j]) flag=1;
            }
            if(flag==0)end++;
        }
       }
        int count=0;
        for(int j=start;count<4&&j<end;j++) {
            cout<<s[j]<<" ";
            count++;
        }
        if(start==end&& start==n-1) cout<<s[n-1];
        cout<<endl;
    
    }
}
