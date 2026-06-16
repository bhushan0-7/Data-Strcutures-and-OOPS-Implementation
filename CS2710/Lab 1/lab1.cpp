#include <iostream>
#include <string.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    // take the gene string as input
    int n;
    cin>>n;
    // take the no of substrings that we need to search for
    while(n--) {
        string search;
        cin>>search;
        // taking the substring that we need to search
        int count=0;
        // count tracks the no of occurences of the substring
        int len=s.size();
        // len is the size of the gene string
        size_t len1=s.size();
        int num[len];
        // creating a array of size len to keep track of the indices of occurences 
        for(size_t i=0;i<len1;i++) num[i]=0;
        // initilising the elements of the array to 0
        for(size_t i=0;i<s.size();i++){
            if(s[i]==search[0]) {
                // checking whether the first char in substring matches ,if matches search for remaining substring
                int flag=0;
                // flag =0 indicates substring matches
                for(size_t j=0;j<search.size();j++){
                    if(s[i+j]!=search[j]) {
                        flag=1;
                        // if substring does not match make flag =1
                        break;
                    }
                }
                if(flag==0) {
                    //flag=0 means substring is matched so increasing count and storing the index of occurence
                     num[count]=i;
                    count++;
                }
            }
        }
    cout<<count<<" ";
    // printing count
    for(int i=0;i<count;i++) cout<<num[i]<<" ";
    // printing indices of occurence 
    cout<<endl;

    }
}