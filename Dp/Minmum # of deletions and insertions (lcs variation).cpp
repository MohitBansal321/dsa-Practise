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
            int deletion=text1.length()-dp[len1][len2];
            int insertion=text2.length()-dp[len1][len2];
            return insertion+deletion;
        }
	int minOperations(string str1, string str2) 
	{ 
        int len1=str1.length();
        int len2=str2.length();
        return solve(str1,str2,len1,len2);
	} 
};
