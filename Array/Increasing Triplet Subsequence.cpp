class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int lft=INT_MAX;
        int mid=INT_MAX;
        for(int i:nums){
            if(i<=lft){
                lft=i;
            }
            else if(i<=mid){
                mid=i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};