#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{ 
  // for storing all sum values
	vector<int> sumStore;
    int n=arr.size();
  //checking particular sum value
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }
  //sort sumstore vector for getting kth position largest subarray sum
    sort(sumStore.begin(),sumStore.end() );
  // return that kth value
    return sumStore[sumStore.size()-k];
}
