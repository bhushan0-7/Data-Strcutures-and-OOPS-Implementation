#include <iostream>
using namespace std;
class Node {
    public:
    int val;
    Node *next;
};
class LinkedList{
    public:
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
int main(){
    int n;
    cin>>n;
    LinkedList L;
    L.create();
    for(int i=0;i<n;i++) {
        Node *a=new Node();
                int temp;
                cin>>temp;
                a->val=temp;
                a->next=NULL;
              L.insertback(a);
    }
    Node *temp=L.head;
    Node *prev=L.head;
    int a=0,b=0,c=0;
    temp=temp->next;
    int count=1;
    int d=0;
    int min=0;
    int max=0;
    while(temp->next!=NULL) {
        if((prev->val > temp-> val) && (temp->val < (temp->next)->val)) {
            if(d==0) {
                a=count;
                b=count;
                c=count;
        }
            else {
                b=c;
                c=count;
            }
             if(d==2) {
            min=b-a;
        }
            d++;
            if(c-b < min) min=c-b;
        }
        prev=temp;
        count++;
        temp=temp->next;
        }
        max=c-a;
        if(d>2) cout<<min<<" "<<max<<endl;
        else if(d<2) cout<<"-1 -1"<<endl;
        else cout<<c-a<<" "<<c-a<<endl;
   
    }