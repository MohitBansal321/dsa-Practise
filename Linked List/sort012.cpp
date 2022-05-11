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
void insertTail(Node* &tail,Node* curr){
	tail->next=curr;
	tail=curr;
}
Node* sortList(Node *head)
{
        // create three list with dummy nodes
	Node* zerohead=new Node(-1);
	Node* zerotail=zerohead;
	Node* onehead=new Node(-1);
	Node* onetail=onehead;
	Node* twohead=new Node(-1);
	Node* twotail=twohead;
	
	Node* curr=head;
	//insertation in three list
	while(curr!=NULL){
		int val=curr->data;
		if(val==0){
			insertTail(zerotail,curr);
		}
		else if(val==1){
			insertTail(onetail,curr);
		}
		else{
			insertTail(twotail,curr);
		}
		curr=curr->next;
	}
	//merge three list
	if(onehead->next!=NULL){
		//if onehead list is not empty
		zerotail->next=onehead->next;
	}
	else{
		//if onehead list is empty
		zerotail->next=twohead->next;
	}
	onetail->next=twohead->next;
	twotail->next=NULL;
	// setup head
	head=zerohead->next;
	// delete dummy nodes
	delete zerohead;
	delete onehead;
	delete twohead;
	return head;
}

