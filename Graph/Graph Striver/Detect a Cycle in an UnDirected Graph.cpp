class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectBfs(int src,vector<int> adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode,node});
                }
                else if(parent!=adjNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectBfs(i,adj,vis)) return true;
            }
        }
        return false;
    }
};


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectdfs(int node,int parent,vector<int> adj[],int vis[]){
        vis[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                if(detectdfs(adjNode,node,adj,vis)==true){
                    return true;
                }
            }
            else if(parent!=adjNode){
                    return true;
                }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectdfs(i,-1,adj,vis)==true) return true;
            }
        }
        return false;
    }
};
