// Greedy Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int reach=0;
        for(int i=0;i<nums.size();i++){
            if(i>reach) return false;
            reach=max(reach,i+nums[i]);
        }
        return true;
    }
};