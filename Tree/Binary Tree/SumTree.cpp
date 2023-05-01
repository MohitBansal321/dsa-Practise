class Solution
{
    public:
    bool res=true;
    int sum(Node* root){
        if(root==NULL) return 0;
        int left=sum(root->left);
        int right=sum(root->right);
        if(root->left==NULL && root->right==NULL) return root->data;
        if(root->data!=left+right){
            res=false;
        }
        return left+right+root->data;
    }
    bool isSumTree(Node* root)
    {
         if(root==NULL) return true;
         sum(root);
         return res;
    }
};