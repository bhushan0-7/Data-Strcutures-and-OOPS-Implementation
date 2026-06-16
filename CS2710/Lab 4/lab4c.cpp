#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Node {
    public:
    char val;
    Node *next;
};
// Node that stores a character and pointer to next node
class stack{
    private:
    Node *head;
    public:
    void create(); //creates a empty simple linked list 
    void push(char n); // push the character n at the begin
    void print(); // printing the stack from top to bottom
    char pop(); //removing the first element from the beginning 
    bool IsEmpty();// returns true if the head is NULL
    char top();//returns the chararcter at the beginning
};

void stack::create(){
    head=NULL; //creates a empty stack
}
char stack::top(){
    Node *temp=head;
    return temp->val; // returns the value present at the beggining of the linked list
}
char stack::pop(){
    Node *temp=head; 
     if(head!=NULL) { // checks whether empty or not
     if(head->next==NULL) {
        head=NULL;
        return temp->val;
     } // if only one node is present then head should become  NULL and returning the value present at that node 
     else {
        head=head->next;
        //else just the change head to head->next so that it points to next node
    }
}
    return temp->val;
}
bool stack::IsEmpty(){
    if(head==NULL) return true; // returns true if stack is empty.
    return false;
}
void stack::push(char n) { //pushing the character at front
    Node *a=new Node();
    a->val=n;
    if(head==NULL) {
        head=a;
        a->next=NULL;
    }
    // if head is null head should point to this new node
    else {
    a->next=head;
    head=a;
    }
    //pointing head to this new node and a to node which head is originally pointing
}

void stack::print(){ 
    // for printing poping the last element and printing it.
     Node *temp=head;
    while(temp!=NULL&&head!=NULL) {
     temp=head;
     Node *prev=NULL;
     if(temp->next==NULL) {
        cout<<head->val<<" ";
        head=NULL;
     }
     //popping out if there is only one node.
     else {
     while(temp->next!=NULL) {
        prev=temp;
        temp=temp->next;
     }
     //finding the last node printing the value in it and popping it out.
      cout<<temp->val<<" ";
      prev->next=NULL;
}
    }
}
int main(){
    string s;
    //storing the paranthesis in a string
    stack L;
    // creating a object of class stack
    L.create();\
    // creating a empty stack
    int flag=0;
    // flag checks whether open and closed paranthesis are matched or not
    cin>>s;
    // taking parenthesis as input
    for(size_t i=0;i<s.size();i++) {
        char temp=s[i];
        //if char is a opening parenthesis then push at front to the original stack
        if(temp=='('|| temp=='{'||temp=='[') {
            L.push(temp);
        }
        // if its a closing bracket then check whether the character just before the closing parenthesis
        else if(L.IsEmpty()!=true) {
            if((temp==')'&&L.top()=='(') || (temp==']'&&L.top()=='[')||(temp=='}'&&L.top()=='{')){
            L.pop();
            // if opening and closing parenthsis match pop out the open paranthesis
            }
            else flag=1;
            //flag=1 indicates parenthesis is not valid
        }
        else flag=1;
        if(flag==1) break; // since flag=1 break out of the loop
    }
    // paranthesis is valid iff stack is empty at the end and flag=0
    if((L.IsEmpty()==true)&&flag==0) cout<<"True"<<endl;
    else cout<<"False"<<endl; //printing true if valid else printing no.
        
}