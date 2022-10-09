// https://leetcode.com/problems/odd-even-linked-list/submissions/     
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr=head;
        ListNode* even=head->next;
        while(curr!=NULL && curr->next!=NULL){
          curr->next=even->next;
          curr=curr->next;
          even->next=curr->next;
          curr->next=even;
          even=even->next;
        }
        return head;
    }
};
