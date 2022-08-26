#include<list>
#include<unordered_map>
bool checkCycleDFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> &adj){
    visited[node]=true;
    dfsVisited[node]=true;
    // check adjcent node of every node
    for(auto num:adj[node]){
        if(!visited[num]){
            bool cycleDetect=checkCycleDFS(num,visited,dfsVisited,adj);
            if(cycleDetect)
                return true;
        }
        // check if node is visited and dfsvistied also
        else if(dfsVisited[num])
            return true;
    }
    // this do because when you return from revursive call then you need to remove its present 
    dfsVisited[node]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    // adjaceny list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;
      adj[u].push_back(v);
      }
    // track of every node visited or not 
    unordered_map<int,bool> visited;
    // track of every dfs call it is visited or not dynamically
    unordered_map<int,bool> dfsVisited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            // function call
            bool cycleFound=checkCycleDFS(i,visited,dfsVisited,adj);
            if(cycleFound)
                return true;
        }
    }
    return false;
}
