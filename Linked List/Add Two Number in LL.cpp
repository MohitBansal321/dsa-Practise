class Solution
{   
    private:
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct Node* add(struct Node* first,struct Node* second){
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        while(first!=NULL && second!=NULL){
            int sum=carry + first->data + second->data;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
            int sum=carry + first->data;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            first=first->next;
        }
        while(second!=NULL){
            int sum=carry + second->data;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            second=second->next;
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
        }
        return ansHead;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        Node* ans=add(first,second);
        ans=reverse(ans);
        return ans;
        
    }
};

// APProach 2------------------------------------------------------------------------------------------------------------------------------------------------

class Solution
{   
    public:
    //Function to add two numbers represented by linked list.
    Node* reverseLL(Node* head){
        Node* curr=head;
        Node* nextNode;
        Node* prev=NULL;
        while(curr!=NULL){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* curr1=reverseLL(first);
        Node* curr2=reverseLL(second);
        Node* new_list=new Node(-1);
        Node* new_curr=new_list;
        int carry=0;
        while(curr1!=NULL || curr2!=NULL || carry==1){
            int sum=0;
            if(curr1!=NULL){
                sum+=curr1->data;
                curr1=curr1->next;
            }
            if(curr2!=NULL){
                sum+=curr2->data;
                curr2=curr2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* temp=new Node(sum%10);
            new_curr->next=temp;
            new_curr=new_curr->next;
        }
        
        return reverseLL(new_list->next);
    }
};

