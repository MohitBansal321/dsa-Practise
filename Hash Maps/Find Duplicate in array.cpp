#include<unordered_map>
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
        if(m[arr[i]]>1){
            return arr[i];
        }
    }
    return 0;
}
