Node* reverseDLL(Node * head)
{   Node* curr=head;
    if(curr==NULL){
        return NULL;
    }
    if(curr->next==NULL){
        
        return head;
    }
    Node* nextNode=NULL;
    while(curr!=NULL){
        nextNode=curr->prev;
        curr->prev=curr->next;
        curr->next=nextNode;
        curr=curr->prev;
    }
    return nextNode->prev;
}
