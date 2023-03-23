class Solution {
	public:
	    int solve(string str1,string str2,int len1,int len2){
	        int dp[len1+1][len2+1];
	        for(int i=0;i<len1+1;i++){
	            dp[i][0]=0;    
	        }
	        for(int i=0;i<len1+1;i++){
	            dp[0][i]=0;
	        }
	        for(int i=1;i<len1+1;i++){
	            for(int j=1;j<len2+1;j++){
	                if(str1[i-1]==str2[j-1] && i!=j){   // important i!=j
	                    dp[i][j]=1+dp[i-1][j-1];
	                }
	                else{
	                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	                }
	            }
	        }
	        return dp[len1][len2];
	    }
		int LongestRepeatingSubsequence(string str){
		    return solve(str,str,str.length(),str.length());
		}

};
