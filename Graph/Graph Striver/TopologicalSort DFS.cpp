class Solution
{   private:
    void dfs(int node,vector<int> adj[],int vis[],stack<int> &s){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis,s);
        }
        s.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,s);
	        }
	    }
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};
