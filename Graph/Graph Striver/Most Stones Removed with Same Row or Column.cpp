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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
//             max row and max col where the stone added its not a size of stones array 
//             its maximun row and col where last stone added
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        
        int cnt=0;
        for(auto it:stoneNodes){
//             now we check unlimate parent of stones which is provided
            if(ds.findUParent(it.first)==it.first){
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};
