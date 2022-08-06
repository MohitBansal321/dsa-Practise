// insertion search remove

#include<iostream>
using namespace std;
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
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode *root,string word){
        // base case
        if(word.length()==0){
            root->isTermial=true;
            return;
        }
        // assumption, word will be in uppercase
        int index=word[0]-'A';
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
    void insertWord(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode *root,string word){
        if(word.length()==0){
            return root->isTermial;
        }
        int index=word[0] - 'A';
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
    bool searchWord(string word){
        return searchUtil(root,word);
    }
    bool removeUtil(TrieNode *root,string word){
        if(word.length()==0){
            root->isTermial=false;
            // cout<<"Element successfully removed"<<endl;
            return true;
        }
        int index=word[0] - 'A';
        TrieNode* child;

        if(root->children[index]!=NULL){
            // present
            child=root->children[index];
            
        }
        else{
            // absent
            // cout<<"Element is not present"<<endl;
            return false;
        }
        return removeUtil(child,word.substr(1));
    }
    void removeWord(string word){
        if(removeUtil(root,word)){
            cout<<"element successfully deleted"<<endl;
        }
        else{
            cout<<"hey boii are you trying to delete the element which is not present"<<endl;
        }
    }
};

int main(){
    Trie *t1=new Trie();
    t1->insertWord("LJJ");
    t1->insertWord("LJJJ");
    cout<<"search word is is present :" << t1->searchWord("LJJ")<<endl;
    t1->removeWord("LJJ");
    cout<<"search word is is present :" << t1->searchWord("LJJJ")<<endl;
    return 0;
}
