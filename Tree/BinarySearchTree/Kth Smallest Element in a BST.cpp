// Brute Force
class Solution {
public:
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        solve(root,temp);
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        return temp[k-1];
    }
};

// optimal

class Solution {
public:
    int ans;
    void solve(TreeNode* root,int &k){
        if(root==NULL) return;
        solve(root->left,k);
        k--;
        if(k==0) {
            ans=root->val;
            return;
        }
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};