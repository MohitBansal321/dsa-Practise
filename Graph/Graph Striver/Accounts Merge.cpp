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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mapMailNode;
        int n=accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
//                when mail is not present in mapping
                if(mapMailNode.find(mail)==mapMailNode.end()){
                    mapMailNode[mail]=i;
                }
                else{
//                  when the other account have same mail we link it with help of dis joint set
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        
//         merge the mails who have same emails
        vector<string> mergeMail[n];
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=ds.findUParent(it.second);
            mergeMail[node].push_back(mail);
        }
//         answer in the form of given input
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
