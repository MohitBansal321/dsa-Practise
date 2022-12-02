class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start]=0;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(int i=0;i<arr.size();i++){
                int num=(arr[i]*node)%100000;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    if(num==end) return dist[num];
                    q.push({num,dist[num]});
                }
            }
        }
        return -1;
    }
};
