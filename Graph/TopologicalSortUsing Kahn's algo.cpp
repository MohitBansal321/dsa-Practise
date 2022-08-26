#include<unordered_map>
#include<list>
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    
    // find all indegree's
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    // push 0 indegree element
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        // store ans
        ans.push_back(front);
        
        // neighour indgree update
        for(auto neighour:adj[front]){
            indegree[neighour]--;
            if(indegree[neighour] ==0){
                q.push(neighour);
            }
        }
    }
    return ans;
}
