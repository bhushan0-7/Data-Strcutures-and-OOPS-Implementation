#include <iostream>
#include <string>
using namespace std;
class dequeue{
    public:
    int arr[100000];
    int _front;
    int _rear;
    int count=0;
    int max;
    dequeue(){
        _front=0;_rear=-1;
    }
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    bool isEmpty();
};
    void dequeue::push_back(int x){
        if(count<max){
          if(_rear!=max-1)_rear++;
          else _rear=0;
          arr[_rear]=x;
          count++;
        }
         else {
            cout<<"Deque is full"<<endl;
         }
    }
    int dequeue::pop_front(){
        int temp;
        if(count!=0) {
         temp=arr[_front];
         cout<<arr[_front]<<endl;
        if(_front!=max-1) _front++;
        else _front=0;
        count--;
        }
        else cout<<"Deque is empty"<<endl;
        return temp;
    }
     bool dequeue::isEmpty(){
        if(count==0) {
            return true;
        }
        return false;
     }
     void dequeue::push_front(int x){
        if(count<max) {
            if(count==0) {
                if(_front!=0) _rear=_front--;
                else _rear=max-1;
            }
            if(_front!=0) _front--;
            else _front=max-1;
            arr[_front]=x;
            count++;
        }
       else cout<<"Deque is full"<<endl;
     }
     int dequeue::pop_back(){
        int temp;
        if(count!=0) {
             temp=arr[_rear];
            if(_rear!=0)
            _rear--;
            else _rear=max-1;
            count--;
            cout<<temp<<endl;
        }
        else cout<<"Deque is empty"<<endl;
        return temp;
     }   
int main(){
    int n;
    cin>>n;
    dequeue q;
    q.max=n;
    int m;
    cin>>m;
    while(m--) {
        string s;
        cin>>s;
        if(s=="push") {
            string temp;
            cin>>temp;
            if(temp=="front") {
                int x;
                cin>>x;
                q.push_front(x);
            }
            else {
                int x;
                cin>>x;
                q.push_back(x);
            }
        }
        if(s=="pop") {
            string temp;
            cin>>temp;
            if(temp=="front") {
               q.pop_front();
            }
            else q.pop_back();
        }
        if(s=="isEmpty") {
            if(!q.isEmpty())
            cout<<"False"<<endl;
            else cout<<"True"<<endl;
        }
    }
    
}
