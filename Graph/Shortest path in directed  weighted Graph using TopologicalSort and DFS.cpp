#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;
class graph{
    public:
    // we make the adjaceny list with weight of node
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printing(){
            for(auto x:adj){
                cout<<x.first<<"->";
                for(auto p:x.second){
                    cout<<"("<<p.first<<","<<p.second<<"),";
                }
                cout<<endl;
            }
    }
    // for topological sort
    void dfs(int node, unordered_map<int,bool> &vis,stack<int> &topo){
        vis[node]=true;
        for(auto neighbour:adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first,vis,topo);
            }
        }
        topo.push(node);
    }
    void getShortestPath(int src,vector<int> &dist,stack<int> &topo){
        dist[src]=0;
        while(!topo.empty()){
        int top=topo.top();
        topo.pop();
        if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dist[top]+i.second<dist[i.first])
                dist[i.first]=dist[top]+i.second;
            }
        }
    }
    }

};
int main(){
    graph d;
    d.addEdge(0,1,5);
    d.addEdge(0,2,3);
    d.addEdge(1,2,2);
    d.addEdge(1,3,6);
    d.addEdge(2,3,7);
    d.addEdge(2,4,4);
    d.addEdge(2,5,2);
    d.addEdge(3,4,-1);
    d.addEdge(4,5,-2);
    d.printing();
    int n=6;
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            d.dfs(i,visited,s);
        }
    }
    int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    d.getShortestPath(src,dist,s);
    cout<<"awser is"<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
    return 0;
}
