class Solution{
  public:
    int  t[1002][1002];
    Solution(){
    memset(t,-1,sizeof(t));
        
    }
    int solve(int price[],vector<int> &len,int n,int lengthOfRod){
        if(n==0 || lengthOfRod==0) return 0;
        if(t[n][lengthOfRod]!=-1) return t[n][lengthOfRod];
        if(len[n-1]<=lengthOfRod){
            return t[n][lengthOfRod]=max(price[n-1]+solve(price,len,n,lengthOfRod-len[n-1]),
                                        solve(price,len,n-1,lengthOfRod));
        }
        else{
            return t[n][lengthOfRod]=solve(price,len,n-1,lengthOfRod);
        }
    }
    int cutRod(int price[], int n) {
        vector<int> len;
        for(int i=1;i<=n;i++){
            len.push_back(i);
        }
        // n=lengthOfROd
        // n=size of length array or price array
        return solve(price,len,n,n);
    }
};
