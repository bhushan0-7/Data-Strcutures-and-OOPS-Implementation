#include <iostream>
#include <string>
using namespace std;
class Queue{
    private:
    int arr[50];
    int _front;
    int _rear;
    public:
    Queue(){
        _front=0;_rear=-1;
    }
    void enque(int x);
    int deque();
    bool isempty();
    int front();
    int rear();
    void print();
};
    void Queue::enque(int x){
          _rear++;
          arr[_rear]=x;
    }
    int Queue::deque(){
        int temp=arr[_front];
        _front++;
        return temp;
    }
     bool Queue::isempty(){
        if(_front==0&& _rear==-1) {
            return true;
        }
        return false;
     }
     int Queue::front(){
        return arr[_front];
     }
     int Queue::rear(){
        return arr[_rear];
     }
        void Queue::print(){
            for(int i=_front;i<_rear+1;i++) {
                cout<<arr[i]<<" ";
            }
        }     
int main(){
    int n;
    cin>>n;
    Queue q;
    while(n--) {
        string s;
        cin>>s;
        if(s=="ENQ") {
            int temp;
            cin>>temp;
            q.enque(temp);
        }
        else if(s=="DEQ") {
            if(q.isempty()==true) continue;
            else {
                q.deque();
            }
        }
        else if(s=="FRONT") {
            cout<<q.front()<<endl;
        }
        else {
            cout<<q.rear()<<endl;
        }
    }
    q.print();
    cout<<endl;
}