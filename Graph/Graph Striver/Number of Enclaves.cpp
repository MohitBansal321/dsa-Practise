class Solution {
private: 
    void bfs(int row,int col,vector<vector<int>> &visit,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        visit[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   !visit[nrow][ncol] &&
                   grid[nrow][ncol]==1){
                       visit[nrow][ncol]=1;
                       q.push({nrow,ncol});
                   }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        // traverse first row and last row
        for(int j=0;j<m;j++){
            // first row
            if(!visit[0][j] && grid[0][j]==1){
                bfs(0,j,visit,grid);
            }
            // last row
            if(!visit[n-1][j] && grid[n-1][j]==1){
                bfs(n-1,j,visit,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(!visit[i][0] && grid[i][0]==1){
                bfs(i,0,visit,grid);
            }
            if(!visit[i][m-1] && grid[i][m-1]==1){
                bfs(i,m-1,visit,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};





// --------------------------------------------------OR------------------------------------------------------------------







class Solution {
private: 
    void bfs(int row,int col,vector<vector<int>> &visit,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        visit[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   !visit[nrow][ncol] &&
                   grid[nrow][ncol]==1){
                       visit[nrow][ncol]=1;
                       q.push({nrow,ncol});
                   }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!visit[i][j] && grid[i][j]==1){
                        bfs(i,j,visit,grid);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


