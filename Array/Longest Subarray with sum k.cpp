// Brute Force
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int maxLen=0;
        for(int i=0;i<N;i++){
            
            for(int j=i;j<N;j++){
                int sum=0;
                for(int l=i;l<=j;l++){
                    sum+=A[l];
                }
                if(sum==K){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen;
    } 

};

// 