// INORDER TRAVERSAL AND VECTOR 
class Solution {
public:
    vector<int> s;
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        s.push_back(root->val);
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        solve(root);
        for(int i=1;i<s.size();i++){
            if(s[i-1]>=s[i]){
                return false;
            }
        }
        return true;
    }
};

// USING MIN AND MAX
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
