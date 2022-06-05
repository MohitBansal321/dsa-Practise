#include<iostream>
#include<deque>
using namespace std;
int solve(int *arr,int n,int k){
    deque<int> maxi(k);
    deque<int> mini(k);
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=arr[maxi.front()]+arr[mini.front()];
    for(int i=k;i<n;i++){

        // removal 
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }

        // addition of next element 
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
        // update ans
        ans+=arr[maxi.front()]+arr[mini.front()];
    }
    return ans;
}
int main(){
    int arr[7]={2,5,-1,7,-3,-2,-1};
    int n=7;
    int k=4;
    cout<<solve(arr,n,k)<<endl;
    return 0;
}
