//  -------------------using topological sort using kahan's algo BFS (cycle detection in directed graph) -------------------------------------

class Solution {
private:
    bool istask(int N,vector<int> adj[]){
        int indeg[N]={0};
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0) q.push(i);
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
        // if there is samller or greater size of topo sort it means it have cycle
        if(topo.size()==N) return true;
        return false;
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    return istask(N,adj);
	}
};
