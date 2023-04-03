// Done with level order traversal with small changes
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left!=NULL) q.push(front->left);
                if(front->right!=NULL) q.push(front->right);
            }
//             when we want to change from L->R to R->L 
            if(flag){
                ans.push_back(temp);
                flag=false;
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                flag=true;
            }
        }
        return ans;
    }
    
};
