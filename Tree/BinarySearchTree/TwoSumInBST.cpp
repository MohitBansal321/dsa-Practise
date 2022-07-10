void solve(BinaryTreeNode<int>* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> ans;
    solve(root,ans);
    int i=0,j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==target){
            return true;
        }
        if(ans[i]+ans[j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
