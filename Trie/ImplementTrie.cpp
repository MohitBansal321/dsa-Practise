/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTermial;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTermial=false;
    }
};

class Trie {
     TrieNode* root;
public:
     
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode *root,string word){
        // base case
        if(word.length()==0){
            root->isTermial=true;
            return;
        }
        // assumption, word will be in uppercase
        int index=word[0]-'a';
        TrieNode *child;

        // element is present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        // absent
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        } 
        // recursion call
        insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode *root,string word){
        if(word.length()==0){
            return root->isTermial;
        }
        int index=word[0] - 'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            // present
            child=root->children[index];
        }
        else{
            // absent
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        int index=word[0] - 'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            // present
            child=root->children[index];
        }
        else{
            // absent
            return false;
        }
        return prefixUtil(child,word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};
