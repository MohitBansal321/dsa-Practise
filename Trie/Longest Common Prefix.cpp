string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];
        bool match=true;
        for(int j=1;j<n;j++){
            // not match 
            if(arr[j].size()<i || arr[j][i]!=ch){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}


