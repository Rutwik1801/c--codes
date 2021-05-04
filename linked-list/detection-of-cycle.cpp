#include<iostream>
using namespace std;

// we use floyyds algorithm here





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



// code to make a cycle;

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(pos==count){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}


// -----------------------


// code to detect a cycle


// we keep two pointers, slow and fast;
// slow moves one step while fast moves two steps at a time
// if these two meet at a point , there is a cycle
// if fast becomes null, there is no cycle

bool detectCycle(node* &head){
    node* temp=head;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
   return false;

}


// ----------------------------------------


// code to remove a cycle

// jaise hi fast==slow ho jaega,hum fast ko head pe le jaenge
// phir fast and slow dono ko ek ek step aage krenge
// jab fast aur slow dono ke next same element ko point krenge,tab slow ke next ko null pe point kra denge
// job done

node* removeCycle(node* & head){
    node* temp=head;
    node* fast=temp;
    node* slow=temp;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            fast=head;
            break;
        }
    }

    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
    return head;

}

// ---------------------------------------------------


int main(){
 node* head=NULL;
   insertAtTail(head,1);
   insertAtTail(head,2);
   insertAtTail(head,3);
   insertAtTail(head,4);
   insertAtTail(head,5);
   insertAtTail(head,6);
   insertAtTail(head,7);
   insertAtTail(head,8);
   makeCycle(head,4);
   removeCycle(head);
 displayLinkedList(head);
//    cout<<detectCycle(head);
    return 0;
}