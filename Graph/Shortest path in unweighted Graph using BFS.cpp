#include<unordered_map>
#include<list>
#include<queue>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int source , int destitaion){
    // making of adjancey list
    unordered_map<int, list <int> > adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(source);
    parent[source]=-1;
    visited[source]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
            else{
                
            }
        }
    }
    vector<int> ans;
    // store the last elment so we can get the source node
    int currNode=destitaion;
    ans.push_back(destitaion);
    while(currNode!=source){
        currNode=parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
