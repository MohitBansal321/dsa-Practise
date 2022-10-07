// Question Link  :  https://practice.geeksforgeeks.org/problems/find-length-of-loop/1

int lenOfLoop(Node* slow,int count){
    Node* temp=slow;
    do{
        count++;
        temp=temp->next;
    }while(temp!=slow);
    return count;
}
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    Node* slow=head;
    Node* fast=head->next;
    int count=0;
    while(fast!=NULL && fast->next!=NULL){
        if(slow==fast){
            return lenOfLoop(slow,count);
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return 0;
}
