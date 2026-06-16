#include <iostream>
#include <string.h>
using namespace std;
class Node {
    public:
    int val;
    Node *next;
};
class LinkedList{
    private:
    Node *head;
    public:
    void create();
    void print();
    void insertfront(Node *a);
    void insertback(Node *a);
    void clear(int z);
};
void LinkedList::print(){
    Node *temp=head;
    while(temp!=NULL) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void LinkedList::create(){
    head=NULL;
}
void LinkedList::insertfront(Node *a){
    if(head==NULL) {
        head=a;
        a->next=NULL;
    }
    else {
    a->next=head;
    head=a;
    }
}
void LinkedList::insertback(Node *a) {
      if(head==NULL) {
        head=a;
        a->next=NULL;
      }
      else {
        Node *temp;
        for(temp=head;temp->next;temp=temp->next);
        temp->next=a;
        a->next=NULL;
      }
}
void LinkedList::clear(int z) {
       Node *prev=NULL;
       Node *temp=head;
       for(;temp;) {
        if(temp->val==z) {
            if(prev==NULL){
                head=temp->next;
                temp=head;
            }
            else {
                prev->next=temp->next;
                temp=temp->next;
            }
           return;
        }
        else {
            prev=temp;
            temp=temp->next;
        }
       }
}
using namespace std;
int main(){
    int n;
    cin>>n;
    LinkedList L;
        while(n--) {
            string s;
            cin>>s;
            if(s=="NEW") {
                L.create();
            }
            else if(s=="PB") {
                Node *a =new Node();
                int temp;
                cin>>temp;
                a->val=temp;
                L.insertfront(a);
            }
            else if(s=="PE") {
                Node *a=new Node();
                int temp;
                cin>>temp;
                a->val=temp;
                a->next=NULL;
                L.insertback(a);
            }
            else {
                int z;
                cin>>z;
                L.clear(z);
            }
        }
        L.print();
        
}