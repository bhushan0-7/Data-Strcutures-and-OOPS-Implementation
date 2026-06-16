#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
class treenode{
    public:
      int c;
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
        void post(treenode* &root,vector<int> &res);
        void insert(treenode * &root,int x);
        void postorder(){
            vector <int> res;
           post(root,res);
           for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        };
};
void binarytree::post(treenode* &root,vector<int> &res) {
    if(root) {
        post(root->left,res);
        post(root->right,res);
        res.push_back(root->c);
    }
    else return;
}
void binarytree::insert(treenode* &root,int x){
   if(root==NULL){
    root=new treenode();
    root->c=x;
    return;
   }
   if(root-> c > x) {
       if(root->left==NULL) {
        root->left=new treenode();
        root->left->c=x;
       }
       else insert(root->left,x);
   }
   else {
    if(root->right==NULL) {
        root->right=new treenode();
        root->right->c=x;
       }
       else insert(root->right,x);
   }
   return;
}
void binarytree::pre(treenode *root){
    if(root) {
        cout<<root->c<<" ";
        pre(root->left);
        pre(root->right);
    }
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
     int n;
     cin>>n;
     binarytree t;
     while(n>0) {
         int temp;
         cin>>temp;
         t.insert(t.root,temp);
         n--;
     }
    t.postorder();
    cout<<endl;
}