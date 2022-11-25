class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int Row=heights.size();
        int Col=heights[0].size();
        priority_queue<
           pair<int,pair<int,int>>,
           vector<pair<int,pair<int,int>>>,
           greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(Row,vector<int>(Col,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==Row-1 && col==Col-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<Row &&
                   ncol>=0 && ncol<Col ){
                int newEff=max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                 if(newEff<dist[nrow][ncol]){
                     dist[nrow][ncol]=newEff;
                     pq.push({newEff,{nrow,ncol}});
                 }
                
                }
            }
        }
        return 0;
    }
};
