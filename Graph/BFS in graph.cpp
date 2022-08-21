#include<unordered_map>
#include<map>
#include<queue>
#include<list>
#include<set>
void prepareadj(unordered_map<int,set<int>> &adjList,vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto x:adjList[front]){
            if(!visited[x]){
                q.push(x);
                visited[x]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepareadj(adjList,edges);
    
    // BFS Traversal
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
