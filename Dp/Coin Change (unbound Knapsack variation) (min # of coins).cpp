class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0)
            return 0;
        if(n==0)
            return -1;
        int dp[n+1][amount+1]; //top down matirx
        //Filling first row and column
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(j==0){
                    dp[i][j]=0;
                }
                if(i==0){
                //if no coins are present then infinte coins are required to settle
                    dp[i][j]=INT_MAX-1; 
                }
            }
        }
        //Filling second row
        for(int j=1;j<amount+1;j++){
            //if we get amount in multiple of first coin then we simply store the division of the coin
            if(j%coins[0]==0){
                dp[1][j]=j/coins[0];
            }
            else{
                //if no coins are present then infinte coins are required to settle
                dp[1][j]=INT_MAX-1; 
            }
        }
        //Filling rest of the blocks
        for(int i=2;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j>=coins[i-1]){
                    dp[i][j]=min(dp[i][j-coins[i-1]] + 1 , dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // getting max value at the end block means no possible answers are there
        return dp[n][amount]== INT_MAX - 1 ? -1 : dp[n][amount];
 
    }
};
