class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level=0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();
            // erased all words that has been used in previous level to transform
            if(vec.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word=vec.back();
            // store the answer
            if(word==endWord){
                // the first sequence where we reach the end
                if(ans.size()==0){
                    ans.push_back(vec);
                }else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
             for(int i=0;i<word.length();i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on this level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=og;
            }
        }
        return ans;
    }
};
