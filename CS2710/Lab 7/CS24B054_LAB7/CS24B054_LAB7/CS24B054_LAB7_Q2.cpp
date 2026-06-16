#include <iostream>
#include <stack>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    int height;
    Node(){
        left=NULL;
        right=NULL;
        height=0;
    }
};
class AVLtree{
    public:
    Node *root=NULL;
    void post(Node* root);
    int balance(Node* root);
    int height(Node* root);
    void update(Node* &root);
      void insert(Node* &root,int x);
      Node* Insert(Node* root,int x);
      Node* leftrotate(Node* x);
      Node* rightrotate(Node *x);
};
int AVLtree::balance(Node * root) {
  return height(root->left)-height(root->right);
}
int AVLtree::height(Node * root) {
    if(!root) return -1;
    else return root->height;
}
void AVLtree::update(Node* &root) {
     root->height=1+max(height(root->left),height(root->right));
}
Node* AVLtree:: leftrotate(Node *x){
       Node* y =x->left;
     Node *temp=x->right;
        y->right=x;
     x->left=temp;
     update(x);
     update(y);
     return y;
}
Node* AVLtree::rightrotate(Node *x) {
   Node* y =x->right;
     Node *temp=x->left;
     y->left=x;
     x->right=temp;
     update(x);
     update(y);
     return y;
}
void AVLtree::insert(Node* &root,int x){
    if(root==NULL) {
        root=new Node();
        root->val=x;
        return;
    }
    stack<Node*> s;
    s.push(root);
   while(s.top()!=NULL) {
    if(s.top()->val > x) {
        if(s.top()->left==NULL) {
            s.top()->left=new Node();
            s.top()->left->val=x;
        }
        else s.push(s.top()->left);
    }
    else {
        if(s.top()->right==NULL) {
            s.top()->right=new Node();
            s.top()->right->val=x;
        }
        else s.push(s.top()->right);
    }
   }
   while(!s.empty()) {
    Node * temp=s.top();
    s.pop();
    int balfac=balance(temp);
    if(balfac > 1 && x < temp->left->val) {
       s.top()->left=leftrotate(temp); 
    }
    if(balfac < 1 && x > temp->right->val) {
        s.top()->right=rightrotate(temp);
    }
   }
}
void AVLtree::post(Node *root){
    if(root==NULL) return;
    post(root->left);
    post(root->right);
    cout<<root->val<<" ";
}
Node* AVLtree::Insert(Node* root,int x){
     if(root==NULL) {
        root=new Node();
        root->val=x;
        return root;
     }
     if(root-> val > x) root->left=Insert(root->left,x);
     else if(root->val < x) root->right=Insert(root->right,x);
     update(root);
     int fac=balance(root);
     if(fac> 1 && root->left->val > x) return leftrotate(root);
     else if(fac> 1 && root->left->val < x) {
        root->left= rightrotate(root->left);
        return leftrotate(root);
     }
   else  if(fac< -1 && root->right->val < x) return rightrotate(root);
    else if(fac< -1 && root->right->val > x) {
        root->right= leftrotate(root->right);
        return rightrotate(root);
     }
     return root;
}
int main(){
    AVLtree t;
    while(1) {
        string temp;
        cin>>temp;
        if(temp=="PostOrder") {
            t.post(t.root);
            cout<<endl;
            break;
        }
        else {
            int x;
            cin>>x;
           t.root= t.Insert(t.root,x); 
        }
    }
}
