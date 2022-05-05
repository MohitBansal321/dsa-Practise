#include<iostream>
#include<map>
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
node* detectLoop(node* head){
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
bool mapMethod(node* head){
    map<node*,bool> visited;
    node* temp=head;
    while(head!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
    }
    return false;

}
node* startingNodeLoop(node* head){
    if(head==NULL){
        return NULL;
    }
    node* intersection=detectLoop(head);
    node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeLoop(node* head){
     if(head==NULL){
         return ;
     }
     node* startingLoop=startingNodeLoop(head);
     node* temp=startingLoop;
     while(temp->next!=startingLoop){
         temp=temp->next;
     }
     temp->next=NULL;
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
    if(detectLoop(head)!=NULL){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    cout<<mapMethod(head)<<endl;
    cout<<startingNodeLoop(head)->data<<endl;
    removeLoop(head);
    print(head);
    return 0;
}
