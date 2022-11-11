class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indeg[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indeg[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        topo.push_back(front);
	        for(auto i:adj[front]){
	            indeg[i]--;
	            if(indeg[i]==0) q.push(i);
	        }
	    }
	    return topo;
	}
};
