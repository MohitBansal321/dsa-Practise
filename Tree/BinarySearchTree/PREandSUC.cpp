pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pre=-1;
    int suc=-1;
    BinaryTreeNode<int>* temp=root;
    while(temp->data!=key){
        if(temp->data>key){
            suc=temp->data;
            temp=temp->left;
            
        }
        else{
            pre=temp->data;
            temp=temp->right;
            
        }
    }
    BinaryTreeNode<int>* lefttree=temp->left;
    BinaryTreeNode<int>* righttree=temp->right;
    while(lefttree!=NULL){
        pre=lefttree->data;
        lefttree=lefttree->right;
        
    }
    while(righttree!=NULL){
        suc=righttree->data;
        righttree=righttree->left;
    }
    pair<int,int> ans;
    ans.first=pre;
    ans.second=suc;
    return ans;
}
