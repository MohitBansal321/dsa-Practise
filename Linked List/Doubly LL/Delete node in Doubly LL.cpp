class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      Node* curr=head_ref;
      int i=1;
      if(x==1){
          curr=curr->next;
          curr->prev=NULL;
          return curr;
      }
      while(i<x && curr!=NULL){
          curr=curr->next;
          i++;
      }
    
      if(curr->next==NULL){
          curr->prev->next=NULL;
      }
      // LL 1 2 3 4 5 6
      // suppose curr is 3
      // curr  vo element ha jo delete krna ha 
      else{
          curr->prev->next=curr->next;  // esme curr ka prev ko apne curr k next se point karwa rahe ha jise curr ka link khatam ho jyga  2->next=4
          curr->next->prev=curr->prev;  // fer apne curr k next ka prev ko apne curr k prev se store karwa rahe ha  4->prev=2
      } 
      return head_ref;
    }
