#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <char> s;
    string temp="Mohit";
    for(int i=0;i<temp.length();i++){
        s.push(temp[i]);
    }
    string ans="";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<ans<<endl;
    return 0;
}
