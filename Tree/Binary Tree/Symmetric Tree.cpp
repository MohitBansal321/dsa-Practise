// -------------------Used Level Order Traversal ----------------------------

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* left=q.front();
            q.pop();
            TreeNode* right=q.front();
            q.pop();
            if(!left && !right){
                continue;
            }
            if(!left || !right || left->val!=right->val){
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
