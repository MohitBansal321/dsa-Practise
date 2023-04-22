class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* tp=s.top();
            s.pop();
            if(tp){
                s.push(tp->left);
                s.push(tp->right);
                swap(tp->left,tp->right);
            }
        }
        return root;
    }
};

// Recursive
TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    return root;
}