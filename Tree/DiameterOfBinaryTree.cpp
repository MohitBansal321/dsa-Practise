// time comp O(n)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> dia(Node* root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int>  left=dia(root->left);
        pair<int,int>  right=dia(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second + 1;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second) + 1;
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        return dia(root).first;
    }
};

// time comp O(n^2)

class Solution {
    private:
    int height(Node* node){
        // code here 
        if(node==NULL){
        return 0;
    }
    int left=height(node->left);
    int right=height(node->right);
    int ans=max(left,right) + 1;
    return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right)+1;
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};
