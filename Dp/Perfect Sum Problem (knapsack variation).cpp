// ---------------------------------Top-Down Approach ---------------------------------------------------
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        long long int dp[n+1][sum+1];
        long long int mod=1e9+7;
        dp[0][0]=1;
        for(int j=1;j<sum+1;j++) dp[0][j]=0;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]%mod+dp[i-1][j-arr[i-1]]%mod;
                }
                else{
                    dp[i][j]=dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][sum]%mod;
	}
	  
};
