#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertionAtHead(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;

}
bool detectLoop(node* head){
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node *head=new node(10);
    node *tail=head;
    insertionAtHead(head,20);
    insertionAtHead(head,30);
    insertionAtHead(head,40);
    insertionAtHead(head,50);
    insertionAtHead(head,60);
    tail->next=head->next;
    cout<<detectLoop(head);
    // print(head);
    return 0;
}
