class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {   Node* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        int arr[len];
        for(int i=0;i<len;i++){
            arr[i]=temp->data;
            temp=temp->next;
        }
        int s=0;
        int e=len-1;
        while(s<=e){
            if(arr[s]!=arr[e]){
                return false;
            }
            else{
                s++;
                e--;
            }
        }
        return true;
    }
};

