// Greedy Approach
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int steps=0;
        int maxReach=0;
        int end=0;
        for(int i=0;i<nums.size()-1;i++){
            maxReach=max(maxReach,i+nums[i]);
            //  when we reach to maxReach index
            if(i==end){
                steps++;
                end=maxReach;
            }
        }
        return steps;
    }
};