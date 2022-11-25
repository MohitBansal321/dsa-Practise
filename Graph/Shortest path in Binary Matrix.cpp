// -------------------------------------------Dijkstra algo with bfs queue-----------------------------------
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        int Row=grid.size();
        int Col=grid[0].size();
        if(Row==1 && Col==1){
            return 1;
        }
        vector<vector<int>> dist(Row,vector<int>(Col,1e9));
        dist[0][0]=0;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int dis=pq.front().first;
            int row=pq.front().second.first;
            int col=pq.front().second.second;
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0 && nrow<Row &&
                       ncol>=0 && ncol<Col &&
                       grid[nrow][ncol]==0 &&
                       dis+1<dist[nrow][ncol]){
                           cout<<nrow<<ncol<<endl;
                           dist[nrow][ncol]=dis+1;
                           if(nrow==Row-1 && ncol==Col-1){
                               return dist[nrow][ncol];
                           }
                           pq.push({dist[nrow][ncol],{nrow,ncol}});
                       }
                }
            }
        }
        return -1;
    }
};
