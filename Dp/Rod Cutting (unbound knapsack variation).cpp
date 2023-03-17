// ---------------------------RC+ Memorization-----------------------------------------
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

// -------------------------------------------Top Down Approach--------------------------------------
class Solution{
  public:
    int  t[1002][1002];
    Solution(){
    memset(t,-1,sizeof(t));
        
    }
    int solve(int price[],vector<int> &len,int n){
        for(int i=0;i<n+1;i++){
            t[0][i]=0;
            t[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(len[i-1]<=j){
                    t[i][j]=max(price[i-1]+t[i][j-len[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][n];
    }
    int cutRod(int price[], int n) {
        vector<int> len;
        for(int i=1;i<=n;i++){
            len.push_back(i);
        }
        // n=lengthOfROd
        // n=size of length array or price array
        return solve(price,len,n);
    }
};
