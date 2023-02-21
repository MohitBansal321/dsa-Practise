class Solution {
public:
    int findMaxDist(TreeNode* target,unordered_map<TreeNode*,TreeNode*> mpp){
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int time=0;
        while(!q.empty()){
            
            int size=q.size();
            int fl=0;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    fl=1;
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    fl=1;
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(mpp[front] && !visited[mpp[front]]){
                    fl=1;
                    visited[mpp[front]]=true;
                    q.push(mpp[front]);
                }
            }
            if(fl) time++;
        }
        return time;
    }
    TreeNode* markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* front=q.front();
            if(front->val==start) res=front;
            q.pop();
            if(front->left){
                parent_track[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                parent_track[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        TreeNode* target=markParents(root,parent_track,start);
        int maxi=findMaxDist(target,parent_track);
        return maxi;
    }
};
