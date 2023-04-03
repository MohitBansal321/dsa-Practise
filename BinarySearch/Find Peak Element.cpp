class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // When only one element
        if(nums.size()==1) return 0;
        int n=nums.size();

        // Checking 0th/(n-1)th index is peak element 
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        // checking remaining element (why s=1 because we dont want to mid go out of vector)
        //                            (why e=n-2 because we dont want to go mid to out of vector)
        int s=1;
        int e=nums.size()-2;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid-1]){
                e=mid-1;
            }
            else if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
};