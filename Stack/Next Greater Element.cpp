// example 1
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> s;
        vector<long long> ans;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                ans.push_back(-1);
                s.push(arr[i]);
            }
            else{
                if(!s.empty() && arr[i]<s.top()){
                    ans.push_back(s.top());
                    s.push(arr[i]);
                }
                
                else{
                    while(!s.empty() && arr[i]>=s.top()){
                        s.pop();
                    }
                    if(s.empty()){
                        ans.push_back(-1);
                        s.push(arr[i]);
                    }
                    else{
                        ans.push_back(s.top());
                        s.push(arr[i]);
                    }
                    
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// example 2
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n);
        stack<long long> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            long long curr=arr[i];
            while(!s.empty() && s.top()<=curr){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(curr);
        }
        return ans;
    }
};
