approach 1
if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node* new_list=NULL;
    Node* head_ref=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            Node* n=new Node(head1->data);
            if(new_list==NULL){
                new_list=n;
                head_ref=n;
            }
            else{
                new_list->next=n;
            }
            new_list=n;
            head1=head1->next;
        }
        else{
            Node* n=new Node(head2->data);
            if(new_list==NULL){
                new_list=n;
                head_ref=n;
            }
            else{
                new_list->next=n;
            }
            new_list=n;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        new_list->next=head1;
        new_list=head1;
        head1=head1->next;
    }
    
    while(head2!=NULL){
        new_list->next=head2;
        new_list=head2;
        head2=head2->next;
    }
    return head_ref;

apraoch 2
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>*first,Node<int>* second){
	if(first->next==NULL){
		first->next=second;
		return first;
	}
	Node<int>* curr1=first;
	Node<int>* next1=first->next;
	Node<int>* curr2=second;
	Node<int>* next2=second->next;
	while(next1!=NULL && curr2!=NULL){
		if((curr1->data<=curr2->data ) && (curr2->data<=next1->data)){
			curr1->next=curr2;
			next2=curr2->next;
			curr2->next=next1;
			curr1=curr2;
			curr2=next2;
		}
		else{
			curr1=next1;
			next1=next1->next;
			if(next1==NULL){
				curr1->next=curr2;
				return first;
			}
		}
	}
	return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
	if(first==NULL){
		return second;
	}
	if(second==NULL){
		return first;
	}
	if(first->data>=second->data){
		return solve(second,first);
	}
	else{
		return solve(first,second);
	}
}
