class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
//         Count of Lcs string
        int n=str1.length();
        int m=str2.length();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<m+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

//      printing of lcs
        int i=n,j=m;
        string ans;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }
//         This is for when some element of either str1 or str2 left to include
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
