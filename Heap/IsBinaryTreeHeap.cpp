class Solution {
  public:
  // for counting how many nodes present
    int countNodes(struct Node* root){
        if(root==NULL){
            return 0;
        }
        int ans=1+countNodes(root->left)+countNodes(root->right);
        return ans;
    }
  // checking it is stasified heap property complete binary tree
    bool isCBT(struct Node* root,int i,int cnt){
        if(root==NULL){
            return true;
        }
        // check for i not greater then no. of nodes 
        if(i>=cnt){
            return false;
        }
        else{
            bool left=isCBT(root->left,2*i+1,cnt);
            bool right=isCBT(root->right,2*i+2,cnt);
            return (left && right);
        }
    }
  // checking it follow max order of heap or not
    bool isMaxOrder(struct Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->data>root->left->data);
        }
        else{
            bool left=isMaxOrder(root->left);
            bool right=isMaxOrder(root->right);
            return (left && right && 
            (root->data > root->left->data && root->data > root->right->data));
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int size=countNodes(tree);
        if(isCBT(tree,index,size) && isMaxOrder(tree)){
            return true;
        }
        return false;
    }
};
