class Solution {
private:
    bool check(int start,int col,vector<int> adj[],int color[]){
        color[start]=col;
        for(auto i:adj[start]){
            if(color[i]==-1){
                if(check(i,!col,adj,color)==false) return false;
            }
            // check if adjcent node have same color
            else if(color[i]==col){
                return false;
            }
        }
        return true;
    }    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!check(i,0,adj,color)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};
