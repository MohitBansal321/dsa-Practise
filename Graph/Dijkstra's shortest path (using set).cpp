#include<unordered_map>
#include<set>
#include<list>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        }
    // creation of dist vector with INT_MAX
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    // creation of set on basics (distance,node)
    set<pair<int,int>> st;
    // intilize distance and set with source node
    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        // fetch top record
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        // remove top record now
        st.erase(st.begin());
        for(auto sathke:adj[topNode]){
            if(nodeDistance + sathke.second < dist[sathke.first]){
                auto record=st.find(make_pair(dist[sathke.first],sathke.first));
                // if record found then erase it
                if(record!=st.end()){
                    st.erase(record);
                }
                // distance update
            dist[sathke.first]=nodeDistance+sathke.second;
            // record push in set
            st.insert(make_pair(dist[sathke.first],sathke.first));
            }
            
        }
    }
    return dist;
}
