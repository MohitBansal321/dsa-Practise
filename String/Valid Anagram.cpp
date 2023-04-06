class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(mp1.find(t[i])==mp1.end()) return false;
            if(mp1[t[i]]!=mp2[t[i]]) return false;
        }
        return true;
    }
};