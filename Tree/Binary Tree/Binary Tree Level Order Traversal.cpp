class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
//         IF root is Null in starting
        if(root==NULL){
            return ans;
        }
        
//         Used for storing left and right nodes
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
            vector<int> temp;
            for(int i=0;i<count;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left!=NULL)
                    q.push(front->left);
                if(front->right!=NULL)
                    q.push(front->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// ---------------------------------------PreOrder Traversal----------------------------------------
