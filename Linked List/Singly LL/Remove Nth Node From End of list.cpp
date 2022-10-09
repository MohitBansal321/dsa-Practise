// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

int CountLL(ListNode* head){
      ListNode* curr=head;
      int count=0;
      while(curr!=NULL){
        count++;
        curr=curr->next;
      }
      return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n!=0)){
            return NULL;
        }
        if(CountLL(head)==n){
            return head->next;
        }
        int count=CountLL(head)-n;
        ListNode* curr=head;
        while(curr!=NULL && count!=1){
            curr=curr->next;
            count--;
        }
        if(curr!=NULL && curr->next!=NULL)
            curr->next=curr->next->next;
        return head;
    }
};
