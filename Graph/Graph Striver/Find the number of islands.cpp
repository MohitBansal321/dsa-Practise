class Solution {
  private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second; 
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int neighbourRow=row+delrow;
                    int neighbourCol=col+delcol;
                    
                    if(neighbourRow>=0 && neighbourRow<n    && 
                       neighbourCol>=0 && neighbourCol<m    &&
                       grid[neighbourRow][neighbourCol]=='1' &&
                       !vis[neighbourRow][neighbourCol])
                       {
                           vis[neighbourRow][neighbourCol]=1;
                           q.push({neighbourRow,neighbourCol});
                       }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};
