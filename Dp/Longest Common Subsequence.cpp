// ----------------------------------------RC----------------------------------------------------------------------
class Solution {
public:
        
        int solve(string text1,string text2,int len1,int len2){
            if(len1==0 || len2==0) return 0;
            if(text1[len1-1]==text2[len2-1]){
                return 1+solve(text1,text2,len1-1,len2-1);
            }
            else{
                return max(solve(text1,text2,len1-1,len2),solve(text1,text2,len1,len2-1));
            }
        }
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        return solve(text1,text2,len1,len2);
    }
};
// ------------------------------------RC+Memoization TopDown---------------------------------------------------------------
class Solution {
public:
        int dp[1002][1002];
        Solution(){
            memset(dp,-1,sizeof(dp));
        }
        int solve(string text1,string text2,int len1,int len2){
            if(len1==0 || len2==0) return 0;
            if(dp[len1][len2]!=-1) return dp[len1][len2];
            if(text1[len1-1]==text2[len2-1]){
                return dp[len1][len2]=1+solve(text1,text2,len1-1,len2-1);
            }
            else{
                return dp[len1][len2]=max(solve(text1,text2,len1-1,len2),solve(text1,text2,len1,len2-1));
            }
        }
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        return solve(text1,text2,len1,len2);
    }
};

// -----------------------------------Tabulation Bottom up-----------------------------------------

class Solution {
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
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        return solve(text1,text2,len1,len2);
    }
};
