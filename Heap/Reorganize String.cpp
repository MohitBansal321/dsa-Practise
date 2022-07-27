class Solution {
public:
    string reorganizeString(string s) {
        // string ans="";
        unordered_map<char,int> visited;
        for(auto ch:s){
            visited[ch]++;
        }
        priority_queue<pair<int,char>> maxHeap;
        for(auto i:visited){
            maxHeap.push({i.second,i.first});
        }
        string ans="";
        while(maxHeap.size()>1){
            auto [a,b]=maxHeap.top();
            maxHeap.pop();
            auto [c,d]=maxHeap.top();
            maxHeap.pop();
            ans.push_back(b);
            ans.push_back(d);
            a--;
            c--;
            if(a>0){
                maxHeap.push({a,b});
            }
            if(c>0){
                maxHeap.push({c,d});
            }
        }
        if(maxHeap.size()==1){
            auto [a,b]=maxHeap.top();
            maxHeap.pop();
            if(a>1) return "";
            ans.push_back(b);
        }
        return ans;
    }
};
