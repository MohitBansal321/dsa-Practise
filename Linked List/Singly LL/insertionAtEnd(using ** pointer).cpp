#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void insertion(Node** head,int data){
    Node* temp=new Node(data);
    Node* curr=*head;
    if(*head==NULL){
        *head=temp;
        return;     // alerative of return you can use use 'else' and put while in it
      /// if you cannot return then it go in while loop  
    }
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
void printing(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
int main()
{
    cout<<"Hello World";
    Node *head=NULL;
    insertion(&head,4);
    insertion(&head,5);
    insertion(&head,6);
    insertion(&head,7);
    insertion(&head,8);
    insertion(&head,9);
    insertion(&head,4);
    printing(head);
    return 0;
}
