#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node {
    public:
    int val;
    Node *next;
};
class stack{
    private:
    Node *head;
    public:
    void create();
    void push(int n);
    void print();
    int pop();
    bool IsEmpty();
    int top();
};
void stack::create(){
    head=NULL;
}
int stack::top(){
    Node *temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    return temp->val;
}
int stack::pop(){
     Node *temp=head;
     if(head!=NULL) {
     Node *prev=NULL;
     if(head->next==NULL) {
        head=NULL;
        return temp->val;
     }
     else {
     while(temp->next!=NULL) {
        prev=temp;
        temp=temp->next;
     }
      prev->next=NULL;
    }
}
    return temp->val;
}
bool stack::IsEmpty(){
    if(head==NULL) return true;
    return false;
}
void stack::push(int n) {
    Node *a=new Node();
    a->val=n;
    a->next=NULL;
    Node *temp=head;
    if(head==NULL) head=a;
    else {
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=a;
}
}
void stack::print(){
     Node *temp=head;
    while(temp!=NULL&&head!=NULL) {
     temp=head;
     Node *prev=NULL;
     if(temp->next==NULL) {
        cout<<head->val<<" ";
        head=NULL;
     }
     else {
     while(temp->next!=NULL) {
        prev=temp;
        temp=temp->next;
     }
      cout<<temp->val<<" ";
      prev->next=NULL;
}
    }
}
int main(){
    int n;
    cin>>n;
    stack L;
        while(n--) {
            string s;
            cin>>s;
            if(s=="NEW") {
                L.create();
            }
            else if(s=="PUSH") {
                int temp;
                cin>>temp;
                L.push(temp);
            }
            else if(s=="POP") {
                L.pop();
            }
            else {
                if(L.IsEmpty()==false)
              L.top();
            }
        }
        L.print();
        cout<<endl;
        
}