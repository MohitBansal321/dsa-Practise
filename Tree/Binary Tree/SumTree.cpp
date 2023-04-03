 class Solution
{   private:
    pair<bool,int> isSumTreee(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        pair<bool,int> leftAns=isSumTreee(root->left);
        pair<bool,int> rightAns=isSumTreee(root->right);
        
        bool isleftsumtree=leftAns.first;
        bool isrightsumtree=rightAns.first;
        bool condn=root->data==leftAns.second+rightAns.second;
        pair<bool,int> ans;
        if(isleftsumtree && isrightsumtree && condn){
            ans.first=true;
            ans.second=root->data+leftAns.second+rightAns.second;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreee(root).first;
    }
};
