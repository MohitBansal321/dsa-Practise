class Solution
{
    public:
    Node* reverseLL(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* nextNode;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {   Node* curr=reverseLL(head);
        Node* temp=curr;
        while(curr){
            if(curr->next==NULL && curr->data==9){
                curr->data=10;
                return reverseLL(temp);
            }
            if(curr->data==9){
                curr->data=0;
                curr=curr->next;
            }
            else{
                curr->data+=1;
                break;
            }
        }
        
        return reverseLL(temp);
    }
};
