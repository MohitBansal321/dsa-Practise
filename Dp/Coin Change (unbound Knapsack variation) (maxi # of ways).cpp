// ------------------------Coin change ii----------------------------------
class Solution {
public:
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
         int a=amount;
         int dp[n+1][a+1];
        for( int i=0;i<a+1;i++){
            dp[0][i]=0;
        }
        for( int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for( int i=1;i<n+1;i++){
            for( int j=1;j<a+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][a];
    }
};
