// time comp O(n)
class Solution {
public:
    int isHeight(TreeNode* root,int &dia){
        if(root==NULL) return 0;
        int left=isHeight(root->left, dia);
        int right=isHeight(root->right, dia);
        int ans=max(left,right)+1;
        dia=max(dia,left+right+1);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia=0;
        isHeight(root,dia);
        return dia-1;
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
