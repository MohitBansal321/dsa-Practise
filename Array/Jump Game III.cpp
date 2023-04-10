class Solution {
public:
    bool visited[50001];
    bool dfs(vector<int>& arr,int i,int siz){
            if(i<0 || i>=siz || visited[i]) return false;
            if(arr[i]==0) return true;
            visited[i]=true;
        return dfs(arr,i-arr[i],siz) || dfs(arr,i+arr[i],siz);
    }
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr,start,arr.size());
    }
};