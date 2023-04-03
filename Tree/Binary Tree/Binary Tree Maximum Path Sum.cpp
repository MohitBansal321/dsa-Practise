
class Solution {
public:
//     used of concept of diameter or width && height of Tree
    int getSum(TreeNode* root,int &maxi){
        if(root==NULL) return 0;
//         if take 0 when we get -ve value in leftSum or rightSum
        int leftSum=max(0,getSum(root->left,maxi));
        int rightSum=max(0,getSum(root->right,maxi));
//      save max value
        maxi=max(maxi,leftSum+rightSum+root->val);
//         taking max (leftSum +node) or (rightSum + node)
        return max(leftSum,rightSum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        getSum(root,maxi);
        return maxi;
    }
};
