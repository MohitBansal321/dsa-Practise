// Used Binary Search 
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool solve(Node* root,int min,int max){
        if(root==NULL) return true;
        if(root->data>min && root->data<max){
            bool left=solve(root->left,min,root->data);
            bool right=solve(root->right,root->data,max);
            return (left && right);
        }
        else{
            return false;
        }
    }
    bool isBST(Node* root) 
    {
        return solve(root,INT_MIN,INT_MAX);
    }
};
