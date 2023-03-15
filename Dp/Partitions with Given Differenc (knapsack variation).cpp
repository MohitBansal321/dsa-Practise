class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
         int sum=0;
         int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum+=arr[i]%mod;
        }
        if(sum-d<0 || ((d+sum)%2)) return 0;
        int Sum=((sum+d)/2);
        vector<vector<int>> dp(n+1, vector<int>(Sum+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<Sum+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<Sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][Sum]%mod;
    }
};
