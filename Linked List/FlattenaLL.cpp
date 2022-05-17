Node* merge(Node* a , Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->child = merge(a->child , b);
    }
    else{
        result = b;
        result->child = merge(a,b->child);
    }
    result->next = NULL;
    return result;
}
Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL)
        return head;
    return merge(head , flattenLinkedList(head->next));
}
