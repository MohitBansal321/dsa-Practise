#include<unordered_map>
#include<stack>
#include<list>
// TS using DFS 
void topoSort(int node,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    for(auto num:adj[node]){
        if(!visited[num]){
            topoSort(num,visited,s,adj);
        }
    }
    // catch of this TS you have to push elment after end of recursive call
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // adjacney list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
