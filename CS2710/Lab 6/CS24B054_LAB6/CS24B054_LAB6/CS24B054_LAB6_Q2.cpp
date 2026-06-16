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
        treenode *root;
        void inorder(treenode *root);
        void Inorder(){
            inorder(root);
        }
        void pre(treenode * root);
        void Preorder() {
            pre(root);
        }
        string in(treenode* root);
        void infix(string &res) {
           res=in(root);
        }
        void expr_tree(string &s);

};
void binarytree::expr_tree(string &s ){
     stack <treenode*> st;
     for(int i=0;i<s.size();i++) {
        if(s[i]>='a'&& s[i] <='z') {
            treenode* temp=new treenode();
            temp->c=s[i];
            temp->left=NULL;
            temp->right=NULL;
            st.push(temp);
        }
        else {
            treenode *temp1=st.top();st.pop();
            treenode *temp2=st.top();st.pop();
            treenode *temp=new treenode();
            temp->c=s[i];
            temp->left=temp2;
            temp->right=temp1;
            st.push(temp);
        }
     }
     root=st.top();st.pop();
}
void binarytree::pre(treenode *root){
    if(root) {
        cout<<root->c;
        pre(root->left);
        pre(root->right);
    }
}
bool op(char c) {
    if(c>='a' && c<='z') return true;
    return false;
}
string binarytree::in(treenode *root){
   if(root) {
    if(op(root->c)) {
        string temp;
        temp.push_back(root->c);
        return temp;
    }
   string l=in(root->left);
   string r=in(root->right);
   return "("+l+root->c+r+")";
   }
   return NULL;
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
      string s;
      cin>>s;
      binarytree t;
      t.expr_tree(s);
      string res;
      t.infix(res);cout<<res<<endl;
      t.Preorder();cout<<endl;

}