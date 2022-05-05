Node * uniqueSortedList(Node * head) {
    // Write your code here.
	if(head==NULL){
		return NULL;
	}
    // Write your code here
	Node* curr=head;
	
	while(curr!=NULL){
		if((curr->next!=NULL) && curr->data==curr->next->data){
			Node* nextNode=curr->next->next;
			Node* deleteNode=curr->next;
			delete(deleteNode);
			curr->next=nextNode;
		}
		else{
			curr=curr->next;
		}
		
	}
	return head;
}
