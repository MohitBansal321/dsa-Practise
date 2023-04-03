class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left){
                        q.push(front->left);
                        cnt++;
                }
                if(front->right){
                    q.push(front->right);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
