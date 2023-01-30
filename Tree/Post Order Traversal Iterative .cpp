// -------------------------------TWO STACK------------------------------------

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL){
                s1.push(root->left);
            }
            if(root->right!=NULL){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};


// ------------------------------------ONE STACK-----------------------------------------

// Can't thing this algo myself
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* curr) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp=s.top()->right;
                if(temp==NULL){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        return ans;
    }
};
