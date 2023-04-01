class Solution {
public:
    string lcs(string s1,string s2,int len1,int len2){
        int dp[len1+1][len2+1];
        // maintaining a priority queue for {length, index} of substring used while generating longest substring
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<len1+1;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<len1+1;i++){
            for(int j=1;j<len2+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    // there might be the case when the longest substring is not the palindrome so storing
                    // substring with length > 2 as len = 1 is always a palindrome and can return any letter
                    if(dp[i][j]>1) {pq.push({dp[i][j],i});}
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        string ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int len=it.first;
            int i=it.second;
            
            // to generate substring
            for(int k=0;k<len;k++){
                if(s1[i-1-k]==s1[i-1-(len-1-k)]) {ans.push_back(s1[i-1-k]);}
            }
            
            // if ans.size() < len of substring then it is not palindrome we have to check for another substring
            
            if(ans.size()==len){ break;} // if we found the ans then break
            else ans.clear(); // for next iteration
            
        }
        // if there was not palindromic substring of size > 1
        if(ans.empty()) ans=s1[0];
        return ans;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        string m = string(s.rbegin(), s.rend());;
        return lcs(s,m,s.length(),s.length());
    }
};