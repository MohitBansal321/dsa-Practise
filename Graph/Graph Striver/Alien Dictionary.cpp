class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        // traversiong from in pair of string with comapre
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int j=0;j<len;j++){
              // if we get different character in alien dict then we make it a connection with help of graph
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
      // apply topo sort for gettting linear order 
        int indeg[K]={0};
        for(int i=0;i<K;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<K;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            topo.push_back(front);
            for(auto it:adj[front]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        string ans="";
        for(auto i:topo){
            ans=ans+char(i+'a');
        }
        return ans;
    }
};
