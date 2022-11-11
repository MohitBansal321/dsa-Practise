class Solution {
  private:
    bool dfs(int node,vector<int> adj[],int vis[],int path[]){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            //when adjcent  node is not visited
            if(!vis[it]){
                if(dfs(it,adj,vis,path)) return true;
            }
            // when visited adjcent node
            else if(path[it]) return true;
        }
        path[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       int visited[V]={0};
       int pathVisit[V]={0};
       for(int i=0;i<V;i++){
           if(!visited[i]){
               if(dfs(i,adj,visited,pathVisit)){
                   return true;
               }
           }
       }
       return false;
    }
};

// -----------------------------------------------------ONLY VISTED ARRAY--------------------------------------------------------------

class Solution {
  private:
    bool dfs(int node,vector<int> adj[],int vis[]){
        vis[node]=2;
        for(auto it:adj[node]){
            //when adjcent  node is not visited
            if(!vis[it]){
                if(dfs(it,adj,vis)) return true;
            }
            // when visited adjcent node
            else if(vis[it]==2) return true;
        }
        vis[node]=1;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       int visited[V]={0};
       for(int i=0;i<V;i++){
           if(!visited[i]){
               if(dfs(i,adj,visited)){
                   return true;
               }
           }
       }
       return false;
    }
};


// -------------------------------------------------------------- TopoSort kahn's algo using BFS --------------------------------------




class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int indeg[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indeg[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        topo.push_back(front);
	        for(auto i:adj[front]){
	            indeg[i]--;
	            if(indeg[i]==0) q.push(i);
	        }
	    }
	    if(topo.size()!=V){
	        return true;
	    }
	    return false;
    }
};
