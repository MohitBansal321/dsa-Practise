class Solution {
private:
    bool dfs(int node,vector<int> adj[],int vis[],int path[],int check[]){
        vis[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            //when adjcent  node is not visited
            if(!vis[it]){
                if(dfs(it,adj,vis,path,check)) return true;
            }
            // when visited adjcent node
            else if(path[it]) return true;
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int visited[V]={0};
       int pathVisit[V]={0};
       int check[V]={0};
       vector<int> safeNode;
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,adj,visited,pathVisit,check);
           }
       }
       for(int i=0;i<V;i++){
           if(check[i]){
               safeNode.push_back(i);
           }
       }
       return safeNode;
    }
};


// ----------------------------------------------Using BFS TOPOLOGICAL SORT ------------------------------------------------------


class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indeg[V]={0};
        // Reverse the adjcance list
        for(int i=0;i<V;i++){
            // given i->it
            // we change it it->i
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> qt;
        vector<int> ans;
        // all terminal node have 0 indeg;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) qt.push(i);
        }
        while(!qt.empty()){
            int front=qt.front();
            qt.pop();
            ans.push_back(front);
            for(auto i:adjRev[front]){
                indeg[i]--;
                if(indeg[i]==0) qt.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
