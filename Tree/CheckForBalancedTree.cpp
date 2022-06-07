// time complx O(n^2) due to height function call
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

// time complex
class Solution{
    private:
    pair<bool,int> isBalancedfast(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=isBalancedfast(root->left);
        pair<bool,int> right=isBalancedfast(root->right);
        bool leftans=left.first;
        bool rightans=right.first;
        bool diff=abs(left.second-right.second)<=1;
        pair<bool,int> ans;
        ans.second=max(left.second,right.second) + 1;
        if(leftans && rightans && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return isBalancedfast(root).first;
        
    }
};
