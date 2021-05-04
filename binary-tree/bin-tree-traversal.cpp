/*
there are 3 ways to traverse a tree:
             1
           /  \
          2    3
        /  \  / \
       4    5 6  7


1.preorder traversal:(1 2 4 5 3 6 7)
     pehle jis root pe ho uski value likho uske baad
     tree ke left subtree pe jao 
     phir jab left subtrees khatam ho jae
     to right subtrees pe jao


2.inorder traversal:(4 2 5 1 6 3 7)
    pehle jis root pr ho uski value nhi likhenge, 
    uski value tab tak nhi likhenge jab tak uske left subtree ko poori tarah traverse naa kr le

3. postorder traversal:(4 5 2 6 7 3 1 )
pehle poore left subtree ko travel kr li jiye 
phir poore right subtree ko travel kr li jiye
uske baad root ki value likhiye

**********************
hum preorder aur postorder se sirf ek hi unique binary 
tree nhi bana sakte unless wo ek complete/perfect binary tree ho

*/


#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
     inorder(root->right);
   
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
struct node* root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
root->right->left=new node(6);
root->right->right=new node(7);
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
return 0;    
}