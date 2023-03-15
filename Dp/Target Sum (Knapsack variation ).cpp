class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
         int mod=1e9+7;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i]%mod;
        }
        if(sum-target<0 || ((target+sum)%2)) return 0;
        int Sum=((sum-target)/2);
        vector<vector<int>> dp(n+1, vector<int>(Sum+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<Sum+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<Sum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-nums[i-1]])%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][Sum]%mod;

    }
};
