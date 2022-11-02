class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};      // visited array for checking all element are traverse or not
        vis[0]=1;
        queue<int> q;      // used for level order traveral
        vector<int> ans;   // store answer of given graph
        q.push(0);         // intialize queue with given or 0 node
        while(!q.empty()){      // traversal until queue empty
            int front=q.front();    // store front of queue for going to neighbour node
            q.pop();
            ans.push_back(front);
            for(auto i:adj[front]){     // traversing in neighbour nodes
                if(!vis[i]){
                    vis[i]=1;          // marked visited nodes 
                    q.push(i);         // store neighbour nodes
                }
            }
        }
        return ans;                // return answer
    }
};
