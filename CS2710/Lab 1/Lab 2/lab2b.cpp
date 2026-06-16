#include <iostream>
#include <vector>
#include <string>
using namespace std;
// defining a class book and it has data elements title , author, year , pages.
class book {
    public:
     string title; // stores title of the book
    string author;// stores author of the book
     int year; // stores year of publication
     int pages; // stores no of pages in the book
};

void merge(vector<book> &v,int left,int mid,int right,int flag){
    vector<book> v1;
    vector<book> v2;
    // v1 and v2 stores the first and second partitions. 
    for(int i=left;i<=mid;i++) v1.push_back(v[i]); // copying the elements to v1
    for(int i=mid+1;i<=right;i++) v2.push_back(v[i]); // copying the elemnts to v2
    vector<book> v3;
    // v3 is vector obtained by combining v1 and v2 and sorting the whole vector.
        size_t i=0,j=0;
        // i,j represents indices corresponding to v1 and v2 respectively
        if(flag==0)  {
            // flag=0 indicates we are sorting based on year of publication
    while(i!=v1.size()&&j!=v2.size()) {
         // checking which is smaller among v1[i].year and v2[j].year and incrementing the index corresponding to smaller value
           if(v1[i].year < v2[j].year) {
            v3.push_back(v1[i]);
            i++; 
            }
           else if(v1[i].year>v2[j].year){
            v3.push_back(v2[j]);
            j++;
           }
           else {
            // if both the years of publication are equal we need to sort based on title
            if(v1[i].title > v2[j].title) {
                v3.push_back(v2[j]);
                j++;
             }
             // checking which title comes first in lexographic order and pushing it into vector v3
             else {
                v3.push_back(v1[i]);
                i++;
             }
           }
        }
               }
        if(flag==1) {
            // flag=1 indicates we are sorting based on pagecount
             while(i!=v1.size()&&j!=v2.size()) {
            // checking which is smaller among v1[i].pages and v2[j].pages and incrementing the index corresponding to smaller value
             if(v1[i].pages< v2[j].pages) {
              v3.push_back(v1[i]);
              i++;
                }
           else if(v1[i].pages>v2[j].pages){
            v3.push_back(v2[j]);
            j++;
           }
           else {
             // if both have same no of pages  we need to sort based on title
            if(v1[i].title > v2[j].title) {
                v3.push_back(v2[j]);
                j++;
             } // checking which title comes first in lexographic order and pushing it into vector v3
             else {
                v3.push_back(v1[i]);
                i++;
             }
           }
        }
        }
    // if first partition(v1) is iterated completely we need to just copy the remaining elements of v2
    if(i==v1.size()) {
          for(size_t k=j;k<v2.size();k++) v3.push_back(v2[k]);
    }
    // else if second partition is iterated completely we need to push back the remaining elements of v1 to v3
    else if(j==v2.size()){
        for(size_t k=i;k<v1.size();k++) v3.push_back(v1[k]);
    }
    //v3 is sorted now
    for(size_t k=0;k<v3.size();k++) v[k+left]=v3[k];
    // copying the elements of v to the sorted order as in v3
}

void mergesort(vector<book> &v,int left,int right,int flag) {
    int mid=(left+right)/2;
    // computing the middle index of the vector
    if(left<right) {
         // dividing the vector into two halves in which half is from indices left to mid, other is  mid to right
        mergesort(v,left,mid,flag);
        //calling the function to sort the first partition of the vector
        mergesort(v,mid+1,right,flag);
        // calling the function to sort the second partition of the vector
        merge(v,left,mid,right,flag);
        // merging the two partitions of the vector to get the final sorted vector
    }
}
int main() {
    int n;
    cin>>n;
    // taking no of books as input
    vector <book> v(n);
    // defining a vector of type book to store the books details 
    for(int i=0;i<n;i++){
        cin>>v[i].title>>v[i].author>>v[i].year>>v[i].pages;
        // taking title,author,year,pages of each book.
    }
    mergesort(v,0,n-1,0);
    // calling the function to sort books based on year of publication
    cout<<"Books sorted by yearPublished:"<<endl;
    for(int i=0;i<n;i++){
        cout<< v[i].title<<" "<<"("<<v[i].year<<")"<<endl;
    }
    // printing the output as described in the question
     mergesort(v,0,n-1,1);
     // calling the function to sort books based on no of pages in the book
    cout<<"Books sorted by pageCount:"<<endl;
    for(int i=0;i<n;i++){
        cout<< v[i].title<<" "<<"("<<v[i].pages<<" pages"<<")"<<endl;
    }
    // printing the output as described in the question
    
}