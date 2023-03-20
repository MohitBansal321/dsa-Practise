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
            int i=len1,j=len2;
            string temp;
            while(i>0 && j>0){
                if(text1[i-1]==text2[j-1]){
                    temp+=text1[i-1];
                    i--;
                    j--;
                }
                else{
                     if(dp[i][j-1]>dp[i-1][j]){
                         j--;
                     }
                    else{
                        i--;
                    }
                }
            }
            reverse(temp.begin(),temp.end());
            cout<<temp;  // print LCS
            return dp[len1][len2];
            
        }
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        return solve(text1,text2,len1,len2);
    }
};
