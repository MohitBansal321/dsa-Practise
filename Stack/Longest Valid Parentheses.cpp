class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> St;
        St.push(-1);  // make stack not empty 
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){             
                St.push(i);
            }
            else{
                if(!St.empty()){
                    St.pop();
                    
                }
                if(!St.empty()){
                    ans=max(i-St.top(),ans);
                }
                else{
                    St.push(i);
                }
            }
        }
        return ans;
    }
};
