// --------------------------Solve using traaversal technique----------------------------------------------------------- 

class Solution {
 private:
  void dfs(int node,vector<int>adj[],int vis[]){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
            dfs(it,adj,vis);
          }
      }
  }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       vector<int> Adj[V];
       for(int i=0;i<V;i++){
           for(int j=0;j<V;j++){
               if(adj[i][j]==1 && i!=j){
                   Adj[i].push_back(j);
                   Adj[j].push_back(i);
               }
           }
       }
       int vis[V]={0};
       int cnt=0;
       for(int i=0;i<V;i++){
           if(!vis[i]){
           cnt++;
           dfs(i,Adj,vis);
           }
       }
       return cnt;
    }
};

// -----------------------------Using Disjoint set ---------------------------------------
class DisjointSet{
//     rank is used to perform union by rank
//     size is used to perfomr union by size
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUParent(int node){
//         if the parent is found
        if(node==parent[node]) return node;
        
//        we assgin parent to all vertex in the path 
        return parent[node]=findUParent(parent[node]);
    }
//     this rank will help to reduce size of tree
    void unionByRank(int u,int v){
        int ulp_u=findUParent(u); 
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findUParent(u); 
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       DisjointSet ds(V);
       for(int i=0;i<V;i++){
           for(int j=0;j<V;j++){
               if(adj[i][j]==1){
                   ds.unionBySize(i,j);
               }
           }
       }
     int cnt=0;
     for(int i=0;i<V;i++){
       if(ds.parent[i]==i) cnt++;
     }
     return cnt;
    }
};

