// Recursion  (TLE After some cases)
class Solution {
public:
    int solve(int i,int j,int m,int n){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        int left=solve(i,j+1,m,n);
        int right=solve(i+1,j,m,n);
        return left+right;
        
    }
    int uniquePaths(int m, int n) {
        int right=0;
        int down=0;
        return solve(right,down,m,n);
    }
};

// Top down (RC+Memoization)
class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j]=solve(i,j+1,m,n,dp)+solve(i+1,j,m,n,dp);
        
    }
    int uniquePaths(int m, int n) {
        int right=0;
        int down=0;
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return solve(right,down,m,n,dp);
    }
};

// Bottom up (Tabluation)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};