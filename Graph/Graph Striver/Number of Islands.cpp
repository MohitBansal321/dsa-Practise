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
  private:
    bool isVaild(int row,int col,int n,int m){
        return row>=0 && row<n && col>=0 && col<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[4]={-1,0,1,0};
            int dc[4]={0,1,0,-1};
            for(int ind=0;ind<4;ind++){
                int adjr=row+dr[ind];
                int adjc=col+dc[ind];
                if(isVaild(adjr,adjc,n,m)){
                    if(vis[adjr][adjc]==1){
                        int nodeNo=row*m+col;
                        int adjNodeNo=adjr*m+adjc;
                        if(ds.findUParent(nodeNo)!=ds.findUParent(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
