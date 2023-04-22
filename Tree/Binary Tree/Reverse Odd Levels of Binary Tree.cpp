class Solution {
public:
    void solve(TreeNode* left,TreeNode* right,int lvl){
        if(left==NULL && right==NULL) return;
        if(lvl%2==0) swap(left->val,right->val);
        solve(left->left,right->right,lvl+1);
        solve(left->right,right->left,lvl+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,0);
        return root;
    }
};