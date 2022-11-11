class Solution {

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
	    for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
	    int indeg[n];
        for(int i=0;i<n;i++){
            indeg[i]=0;
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) {q.push(i);}
        }
        vector<int> topo;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            topo.push_back(front);
            for(auto it:adj[front]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        if(topo.size()==n) return true;
        
        return false;
    }
};
