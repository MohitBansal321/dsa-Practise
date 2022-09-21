#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
void insertBegin(node* &head,int val){
    node* temp=new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertEnd(node* &head,int val){
    node* temp=new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
}
void insertGiven(node* &head ,int val,int pos){
    node* temp=new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    if(pos==1){
        temp->next=head;
        head->prev=temp;
        head=temp;
        return;
    }
    node* curr=head;
    node* prev=NULL;
    while(pos!=1 && curr!=NULL){
        prev=curr;
        curr=curr->next;
        pos--;
    }
    prev->next=temp;
    temp->prev=prev;
    temp->next=curr;
    curr->prev=temp;
}
void printing(node* head){
    node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    insertBegin(head,5);
    insertBegin(head,4);
    insertBegin(head,3);
    insertBegin(head,2);
    insertBegin(head,1);
    // printing(head);
    insertEnd(head,6);
    insertEnd(head,7);
    insertEnd(head,8);
    insertEnd(head,9);
    printing(head);
    insertGiven(head,32,1);
    printing(head);
    return 0;
}
