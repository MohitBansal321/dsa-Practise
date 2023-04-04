// Two Pointer approach
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        int s_pointer=0;
        int t_pointer=0;
        while(t_pointer<t.length()){
            if(t.at(t_pointer)==s.at(s_pointer)){
                s_pointer++;
                if(s_pointer==s.length()){
                    return true;
                }
            }
            t_pointer++;
        }
        return false;
    }
};

// DP  LCS
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen=s.length();
        int tlen=t.length();
        vector<vector<int>>dp(slen+1,vector<int>(tlen+1,0));
        for(int i=0;i<slen+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<tlen+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<slen+1;i++){
            for(int j=1;j<tlen+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        if(dp[slen][tlen]==slen){
            return true;
        }
        return false;
    }
};

