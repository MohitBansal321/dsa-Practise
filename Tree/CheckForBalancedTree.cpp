// time complex O(n^2) due to height function call
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right) + 1;
        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};

// time complex O(n)
class Solution {
public:
    int isHeight(TreeNode* root){
        if(root==NULL) return 0;
        int left=isHeight(root->left);
        if(left==-1) return -1;
        int right=isHeight(root->right);
        if(right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        return isHeight(root)!=-1;
    }
};
