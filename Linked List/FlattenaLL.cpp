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

// --------------------------Striver Code----------------------------------
Node* mergeList(Node* x,Node* y){
    Node* ans=new Node(0);
    Node* temp=ans;
    while(x!=NULL && y!=NULL){
        if(x->data<y->data){
            temp->bottom=x;
            temp=temp->bottom;
            x=x->bottom;
        }
        else{
            temp->bottom=y;
            temp=temp->bottom;
            y=y->bottom;
        }
    }
    if(x) {temp->bottom=x;}
    else {temp->bottom=y;}
    return ans->bottom;
}
Node *flatten(Node *root)
{
    if(root!=NULL || root->next!=NULL){
        return root;
    }
    root->next=flatten(root->next);
    root=mergeList(root,root->next);
    return root;
}
