// --------------------------Only Recursion----------------------------

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n==0 || W==0){
           return 0;
       }
       if(wt[n-1]<=W){
           return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
       }
       else if(wt[n-1]>W){
           return knapSack(W,wt,val,n-1);
       }
    }
};

// -----------------------------------Recursion with Memorize (DP)--------------------------------------------
class Solution
{   
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int  t[1002][1002];
    Solution(){
    memset(t,-1,sizeof(t));
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n==0 || W==0){
           return 0;
       }
       if(t[n][W]!=-1) return t[n][W];
       if(wt[n-1]<=W){
           return t[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
       }
       else if(wt[n-1]>W){
           return t[n][W]=knapSack(W,wt,val,n-1);
       }
    }
};

// --------------------------Top DOwn Apporach-----------------------------------------

int knapSack(int W, int wt[], int val[], int n) 
    { 
        int t[n+1][W+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<W+1;j++){
                if(i==0 || j==0) t[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1] <= j){
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
