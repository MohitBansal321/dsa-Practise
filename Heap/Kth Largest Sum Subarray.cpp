// apporach one tc 0(n^2(longn)) Sc 0(n^2)
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

// approach second tc 0( n^2 (longn) ) Sc 0(k)
#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{    priority_queue<int,vector<int>,greater<int>> pq;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(pq.size()<k){
                pq.push(sum);
                
            }
            else{  
            pq.push(sum);
            pq.pop();
            }
        }
    }
     return pq.top();
}
