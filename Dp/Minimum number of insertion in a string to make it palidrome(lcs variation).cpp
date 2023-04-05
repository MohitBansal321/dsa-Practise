class Solution{   
public:
    int lcs(string s1,string s2){
        int len1=s1.length();
        int len2=s2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<len1+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<len2+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return len1-dp[len1][len2];
    }
    int findMinInsertions(string S){
        string t=S;
        reverse(S.begin(),S.end());
        return lcs(t,S);
    }
};