class Solution
{   void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    void dfs3(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs3(it,vis,adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
      
        // transpose the graph
        vector<int> adjT[V];  
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
      
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node,vis,adjT);
            }
        }
        return scc;
    }
};
