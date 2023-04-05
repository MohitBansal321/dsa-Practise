// Using Binary Search
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binarySearch(nums,0,nums.size()-1);
    }
    TreeNode* binarySearch(vector<int>nums,int start,int end){
        if(start<=end){
            int mid=start+(end-start)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=binarySearch(nums,start,mid-1);
            root->right=binarySearch(nums,mid+1,end);
            return root;
        }
        return NULL;
    }
};