#include<unordered_map>
#include<list>
#include<stack>
void topoSort(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    // toposort logic
    s.push(node);
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{    
    // adjaceny list
	unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v); 
    }
    // topoSort 
    stack<int> s;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    // transpose of graph
    unordered_map<int,list<int>> transpose;
    for(int i=0;i<v;i++){
        visited[i]=0;
        for(auto nbr:adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    
    // dfs call suing above ordering
    int count=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(!visited[top]){
            count++;
            // we can call dfs without stack "s" too
            // i am done with stack 
            topoSort(top,visited,s,transpose);
        }
    }
    return count;
}
