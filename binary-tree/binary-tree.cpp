#include<iostream>
using namespace std;

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
*/



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


int main(){
struct node* root=new node(1);
root->left=new node(2);
root->right=new node(3);

/*
 
       1
      / \
    2    3
*/

root->left->left=new node(4);
root->right->right=new node(5);
/*
 
       1
      / \
    2    3
  /  \
 4    5
*/
    return 0;
}