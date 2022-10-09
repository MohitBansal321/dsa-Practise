// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/818831389/

class Solution {
public:
    int CountLL(ListNode* head){
      ListNode* curr=head;
      int count=0;
      while(curr!=NULL){
        count++;
        curr=curr->next;
      }
      return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
          return NULL;
        }
        int middle=CountLL(head)/2;
        ListNode* curr=head;
        while(middle!=1){
            middle--;
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};


// other approach
class Solution {
public:
    ListNode* middlePrev(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
          return NULL;
        }
        ListNode* curr=middlePrev(head);
        curr->next=curr->next->next;
        return head;
    }
};
