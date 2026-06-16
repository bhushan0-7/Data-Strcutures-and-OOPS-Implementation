#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<n;i++) {
        if(a[i]>a[i-1]) continue;
        else {
            int j=i;
            while(a[j]<=a[j-1] && j>0) {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                j--;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}