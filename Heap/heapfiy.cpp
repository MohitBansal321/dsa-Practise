#include<iostream>
using namespace std;
void heapfiy(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapfiy(arr,n,largest);
    }
}
int main(){
    int arr[6]={-1,45,872,234,78,12};
    for(int i=5/2;i>0;i--){
        heapfiy(arr,5,i);
    }
    for(int i=1;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
