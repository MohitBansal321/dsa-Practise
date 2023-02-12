class Solution{
    public:
    int x=1;
    void dfs(Node* root){
        if(root==NULL) return;
        if(root->left && root->right && root->left->data+root->right->data!=root->data){
            x=0;
        }
        else if(!root->left && root->right && root->right->data!=root->data){
            x=0;
        }
        else if(!root->right && root->left && root->left->data!=root->data){
            x=0;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int isSumProperty(Node *root)
    {
        dfs(root);
        return x;
    }
};
