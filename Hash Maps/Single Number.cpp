class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1) return it.first;
        }
        return 0;
    }
};

// T:O(n) S:O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};

// T:O(n) S:O(1)