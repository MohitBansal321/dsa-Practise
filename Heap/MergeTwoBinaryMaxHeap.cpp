class Solution{
    public:
    void heapify(vector<int> &ans,int n,int i){
        int largest=i;
        int left=2*i + 1;
        int right=2*i + 2;
        if(left <n && ans[largest] < ans[left]){
            largest=left;
        }
        if(right<n && ans[largest] <ans[right]){
            largest=right;
        }
        if(largest!=i){
            swap(ans[largest],ans[i]);
            heapify(ans,n,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> ans;
      //merge two vector
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int len=ans.size();
      //heapfiy from n/2-1 to 0 element other are heapify due to leaf nodes
        for(int i=len/2 - 1;i>=0;i--){
            heapify(ans,len,i);
        }
        
        return ans;
    }
};
