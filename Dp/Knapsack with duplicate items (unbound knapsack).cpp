class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        for(int i=0;i<N+1;i++){
            for(int j=0;j<W+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<N+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }
};

// ---------------------------RC+ MEMORIZATIOn

class Solution{
public:
    int t[1001][1001];
    
    int helper(int N, int W, int val[], int wt[])
    {
        if(N == 0 || W == 0) return 0;
        
        if(t[N][W] != -1) return t[N][W];
        
        if(wt[N-1] <= W){
            return t[N][W] = max(val[N-1]+helper(N, W-wt[N-1], val, wt), helper(N-1, W, val, wt));
        }
        else{
            return t[N][W] = helper(N-1, W, val, wt);
        }
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(t, -1, sizeof(t));
        return helper(N, W, val, wt);
    }
};
