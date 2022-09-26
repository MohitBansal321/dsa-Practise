#include <iostream>
using namespace std;
// create a data strcutrue for linked list
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

// insertion function for CLL at end
void insert(node* &head,int val){
    node* temp=new node(val);
    node* curr=head;
    if(head==NULL){
        head=temp;
        temp->next=head;
        return;
    }
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
}
// traversal of CLL 
void printing(node* head){
    if(head==NULL){
        cout<<"empty list";
        return;
    }
    node* curr=head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=head);   // this is the condition where we reach the head again 
}
int main()
{
    node* head=NULL;
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    // insert(head,8);
    // insert(head,9);
    // insert(head,10);
    printing(head);
    return 0;
}
