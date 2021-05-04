#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};



// 88888888888888888888888888888888888888888888888888888888
// boilerplate code for a linked list;
// 88888888888888888888

void insertAtTail(node* &head,int val){
     
      node* n=new node(val);
      node* temp=head;

    
    if(head==NULL){
        head=n;
        return;
    }
   
    while(temp->next!=NULL){
        temp=temp->next;
    }
  
    temp->next=n;
}





void insertAtHead(node* &head,int val){
    node* n=new node(val);

    n->next=head;
    
    head=n;

}


bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}




void deleteAtHead(node* head){
    node* toDelete= head;
    head=head->next;
    delete toDelete;
}


void deletion(node* &head,int val){
    node*temp=head;
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    while(temp->next->data!=val){
        temp=temp->next;
    }
   
    node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}

void displayLinkedList(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
// 8888888888888888888888888888888888888888888888888888888888888888888888
// 8888888888888888888888888888888888888888888888888888888
// 88888888888888888888888888888888888888888888
// 8888888888888888

// code to append k nodes

node* appendk(node* & head,int k){
    node* temp=head;
    int length=1;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    node* newHead;
    node* newTail;
    node* tail=head;
    k=k%length;
    int count=1;
    while(tail->next!=NULL){
        if(count==length-k){
            newTail=tail;
        }
        if(count==length-k+1){
            newHead=tail;
        }
        count++;
        tail=tail->next;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}


// -------------------------
int main(){

}