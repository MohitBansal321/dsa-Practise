// replace O with X

class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+delrow[i];
            int newCol=col+delcol[i];
            if(newRow>=0 && newRow<n &&
               newCol>=0 && newCol<m &&
               !vis[newRow][newCol] &&
               board[newRow][newCol]=='O'){
                   dfs(newRow,newCol,vis,board);
               } 
            
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // traverse first row and last row
        for(int j=0;j<m;j++){
            // first row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            // last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }
        // traverse first col and last col
        for(int i=1;i<n;i++){
            // first col
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            // last col
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        // replace 0 with X 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
