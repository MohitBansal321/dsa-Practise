#include<iostream>
#include<map>
#include<list>
using namespace std;
class graph{
    public:
    map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        // direction=0 -> undirected
        // direction=1 -> directed

        // create an edge from u to v
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    graph g;
    cout<<"Enter the number of nodes"<<endl;
    int nodes;
    cin>>nodes;

    cout<<"Enter the number of edges"<<endl;
    int edges;
    cin>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdjList();
    return 0;
}
