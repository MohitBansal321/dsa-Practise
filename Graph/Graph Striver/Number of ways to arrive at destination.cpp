class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            long long u=it[0];
            long long v=it[1];
            long long wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long >>,greater<pair<long long,long long>>> pq;
        vector<long long > ways(n,0);
        vector<long long> dist(n,LONG_MAX);
        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});
        long long mod=(long long)(1e9+7);
        while(!pq.empty()){
            long long  dis=pq.top().first;
            long long  node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjNode=it.first;
                long long  edW=it.second;
                
                if(edW+dis<dist[adjNode]){
                    dist[adjNode]=edW+dis;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(edW+dis==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
