#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
      data=val;
      left=NULL;
      right=NULL;
    }
};



// search function;
int Search(int inorder[],int start,int end,int curr){
    // returns the index of curr int the inorder array so thast it can be positioned int the tree;
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
// ---------------------------------------



// we create a function that returns a node, it takes in both the arrays and the start and end position of the inorder array;
// main tree building function

Node* BuildTree(int preorder[],int inorder[],int start,int end){
// initial condition;
if(start>end){
    return NULL;
}

static int idx=0;
// giving curr variable the value of the element of preorder array;
int curr=preorder[idx];
// then incrementing the value idx
idx++;
// creating a new node with the curr value;
 Node* node=new Node(curr);
 if(start==end){
     return node;
 }

//  search for the index of curr value in the inorder array using search function created above;
 int pos=Search(inorder,start,end,curr);
//  build the left subtree by taking elements to the left of pos value as only that side of array contains the left subtree;
// using recursion here; 
 node->left=BuildTree(preorder,inorder,start,pos-1);
 //  build the right subtree by taking elements to the right of pos value as only that side of array contains the right subtree;
// using recursion here;
 node->right=BuildTree(preorder,inorder,pos+1,end);

}
// ------------------------



// function to print the tree in inorder form;

void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


int main(){
    // we first initialize preorder and inorder arrays
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    // create a root node and passing it in build tree function;
    Node* root=BuildTree(preorder,inorder,0,4);
    Inorder(root);

    return 0;
}

