// Brute Force
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        for(int i=0;i<=n-m;i++){
            int j=0;
            for(;j<m;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};

// KMP ALGO

class Solution {
public:
    void computeLPS(string pattern,int n,vector<int>&lps){
        int i=1;
        int len=0;
        lps[0]=0;
        while(i<n){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        if(n==0) return -1;
        if(n==0 && m==0) return -1;
        if(n>m) return -1;
        vector<int>lps(n);
        computeLPS(needle,n,lps);   // calculate pattern repeating element in needle
        int i=0,j=0;
        while(i<m){
            if(needle[j]==haystack[i]){
                i++;
                j++;
            }
            if(j==n) return i-j;
            if(i<m && needle[j]!=haystack[i]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};

// Sliding Window 

int strStr(string haystack, string needle) {
        string s = "";
        int i = 0;
        int j =0;
        int k = needle.size();
        while(j<haystack.size()){
            s +=haystack[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(s==needle){
                    return i;
                }
                s.erase(0, 1);
                i++;
                j++;
            }
        }
        return -1;
    }