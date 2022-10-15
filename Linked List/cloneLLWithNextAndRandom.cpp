class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp; 
        }
        
        curr=head;
        while(curr){
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;  // go to the next orignal node
        }
        Node* ans=new Node(0);   // dummy node for ans
        Node* temp=ans;         // temp node for reference pointer
        while(head){
            // copy of alernative added node from orignal list
            temp->next=head->next;
            temp=temp->next;
            
            // restoring orignal list
            head->next=head->next->next;
            head=head->next;

        }
        return ans->next;
    }
};
