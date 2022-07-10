void solve(TreeNode<int>* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    
    vector<int> ans;
    solve(root,ans);
    TreeNode<int> *temp=new TreeNode<int>(ans[0]);
    TreeNode<int> *curr=temp;
    for(int i=1;i<ans.size();i++){
        TreeNode<int> *temp1=new TreeNode<int>(ans[i]);
        curr->left=NULL;
        curr->right=temp1;
        curr=temp1;
    }
    curr->left=NULL;
    curr->right=NULL;
    return temp;
}
