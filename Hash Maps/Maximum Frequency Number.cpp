int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> m;
    int maxFreq=0;
    for(auto i:arr){
        m[i]++;
        maxFreq=max(maxFreq,m[i]);
    }
    int ans=-1;
     for(int i=0;i<arr.size();i++){
       // checking which first element come in array have maximum frequency
         if(maxFreq==m[arr[i]]){
             ans=arr[i];
             break;
         }
     }
    return ans;
}
