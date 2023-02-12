// We will perform a special level order traversal with two loops where inner loops traverse the nodes of a single level. This is to ensure that we can do our calculations once a single level is traversed. In the traversal, we will assign an index to a node.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int mmin=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int cur_id=q.front().second-mmin;
                TreeNode* front=q.front().first;
                q.pop();
                if(i==0) first=cur_id;
                if(i==size-1) last=cur_id;
                if(front->left) q.push({front->left,(long long)cur_id*2+1});
                if(front->right) q.push({front->right,(long long)cur_id*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
