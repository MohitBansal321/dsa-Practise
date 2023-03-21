class Solution{
  public:
    int solve(string text1,string text2,int len1,int len2){
                    int dp[len1+1][len2+1];
            for(int i=0;i<len1+1;i++){
                dp[i][0]=0;
            }
            for(int i=0;i<len2+1;i++){
                dp[0][i]=0;
            }
            for(int i=1;i<len1+1;i++){
                for(int j=1;j<len2+1;j++){
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            return dp[len1][len2];
        }
    int longestPalinSubseq(string A) {
        string rev_A = string(A.rbegin(), A.rend());
        return solve(A,rev_A,A.length(),A.length());
    }
};
