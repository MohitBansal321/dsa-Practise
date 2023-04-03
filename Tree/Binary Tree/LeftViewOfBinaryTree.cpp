class Solution
{
    void solve(Node* root,vector<int>& ans,int lvl){
        if(root==NULL)
            return;
        if(lvl==ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->left,ans,lvl+1);
        solve(root->right,ans,lvl+1);
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }
};

// -------------------------- Iterative using level order traversal ----------------------------------------------------------

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            q.pop();
            TreeNode* front=temp.first;
            int lvl=temp.second;
            if(mp.find(lvl)==mp.end(){
                mp[lvl]=front->val;
            }
            if(front->left) q.push({front->left,lvl+1});
            if(front->right) q.push({front->right,lvl+1});
            
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
