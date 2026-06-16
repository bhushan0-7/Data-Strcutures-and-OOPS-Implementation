#include <iostream>
#include <string>
#include <stack>
using namespace std;
class treenode{
    public:
      char c;
      treenode* left;
      treenode* right;
};
class binarytree{
        public:
        treenode *root=NULL;
        void inorder(treenode *root);
        void Inorder(){
            inorder(root);
        }
        void pre(treenode * root);
        void Preorder() {
            pre(root);
        }
        void create(string s){
        }
        binarytree& NewickToBinaryTree(string s);
        bool isBST(string);
};
binarytree& binarytree::NewickToBinaryTree(string s){
    stack <char> c;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') c.push(s[i]);
        else if (s[i]==',') continue;
        else if(s[i]>='A'&& s[i]<='B') c.push(s[i]);
        else if(s[i]==')') {
            char a=c.top();c.pop();
            char b=c.top();c.pop();
        }
    }
}
void binarytree::pre(treenode *root){
    if(root) {
        cout<<root->c;binarytree& NewickToBinaryTree(string s);
        pre(root->left);
        pre(root->right);
    }
}
bool op(char c) {
    if(c>='a' && c<='z') return true;
    return false;
}
void binarytree::inorder(treenode *root){
    if(root) {
        inorder(root->left);
        cout<<root->c;
        inorder(root->right);
    }
    return;
}
int main(){
     binarytree temp,t;
     string s;cin>>s;
     t=temp.NewickToBinaryTree(s);
     t.Inorder();cout<<endl;
     t.Preorder();cout<<endl;
}