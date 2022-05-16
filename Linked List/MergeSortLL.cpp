/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head){
	node* slow=head;
	node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
} 
node* merge(node* &first,node* &second){
	if(first==NULL){
		return second;
	}
	if(second==NULL){
		return first;
	}
	node* ans=new node(-1);
	node* temp=ans;
	while(first!=NULL && second!=NULL){
		if(first->data<second->data){
			temp->next=first;
			temp=first;
			first=first->next;
		}
		else{
			temp->next=second;
			temp=second;
			second=second->next;
		}
	}
	while(first!=NULL){
		temp->next=first;
		temp=first;
		first=first->next;
	}
	while(second!=NULL){
		temp->next=second;
		temp=second;
		second=second->next;
	}
	ans=ans->next;
	return ans;
}
node* mergeSort(node *head) {
    // Write your code here.
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* mid=findmid(head);
	node* left=head;
	node* right=mid->next;
	mid->next=NULL;
	
	left=mergeSort(left);
	right=mergeSort(right);
	
	node* res=merge(left,right);
	return res;
}
