/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
// Brute force approach
Node* sortList(Node *head)
{
    // Write your code here.
	int count0=0;
	int count1=0;
	int count2=0;
	Node* temp=head;
	while(temp!=NULL){
		if(temp->data==0){
			count0++;
		}
		else if(temp->data==1){
			count1++;
		}
		else{
			count2++;
		}
		temp=temp->next;
	}
	temp=head;
	while(temp!=NULL){
		if(count0!=0){
			temp->data=0;
			count0--;
		}
		else if(count1!=0){
			temp->data=1;
			count1--;
		}
		else if(count2!=0){
			temp->data=2;
			count2--;
		}
		temp=temp->next;
	}
	return head;
}

// optimal approach


