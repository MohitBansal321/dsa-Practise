// finding no. of connected components + no. of extra edges using disjoint set
class DisjointSet{
//     rank is used to perform union by rank
//     size is used to perfomr union by size
    
    public:
    vector<int> rank,parent,size;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtraEd=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
//             this is the case when u and v is connected to same parent already 
            if(ds.findUParent(u)==ds.findUParent(v)){
                cntExtraEd++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int NoOfComp=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                NoOfComp++;
            }
        }
        if(cntExtraEd>=NoOfComp-1){
            return NoOfComp-1;
        }
        return -1;
    }
};
