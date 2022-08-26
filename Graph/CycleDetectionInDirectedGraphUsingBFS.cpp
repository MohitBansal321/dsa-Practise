#include<list>
#include<unordered_map>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first - 1;  // to make the graph start from 0 
        int v=edges[i].second - 1;  // to make the graph start from 0
        adj[u].push_back(v);
    }
    
    // find all indegree's
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    // push 0 indegree element
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // do bfs
    int count=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        // store ans
        count++;
        
        // neighour indgree update
        for(auto neighour:adj[front]){
            indegree[neighour]--;
            if(indegree[neighour] ==0){
                q.push(neighour);
            }
        }
    }
    if(count==n){
        return false;
    }
    else{
        return true;
    }
}
