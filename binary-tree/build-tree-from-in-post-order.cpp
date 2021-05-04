#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};


int Search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}


Node* BuildTree(int inorder[],int postorder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int idx=6;
    int curr=postorder[idx];
    idx--;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=Search(inorder,start,end,curr);
     node->right=BuildTree(inorder,postorder,pos+1,end);
    node->left=BuildTree(inorder,postorder,start,pos-1);

}

void PrintInorder(Node* root){
    if(root==NULL){
        return;
    }
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}



int main(){
    int inorder[]={4,2,5,1,6,3,7};
    int postorder[]={4,5,2,6,7,3,1};
    Node* root= BuildTree(inorder,postorder,0,6);
    PrintInorder(root);
    return 0;
}