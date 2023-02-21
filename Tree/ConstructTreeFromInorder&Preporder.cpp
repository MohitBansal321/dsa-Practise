class Solution{
    public:
    int findPostion(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
        if(index >=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element=pre[index++];
        Node* root=new Node(element);
        int position=findPostion(in,element,n);
        root->left=solve(in,pre,index,inorderStart,position-1,n);
        root->right=solve(in,pre,index,position+1,inorderEnd,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex=0;
        Node *ans=solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};

// -------------------------------------------------------------------------------------------------------------------------------------

TreeNode* buildTree(vector<int>&preorder,int preStart,int preEnd,
                        vector<int>&inorder,int inStart,int inEnd,map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[root->val];
        int numLeft=inRoot-inStart;
        root->left=buildTree(preorder,preStart+1,preStart+numLeft,
                             inorder, inStart,inRoot-1,mp);
        root->right=buildTree(preorder,preStart+numLeft+1,preEnd,
                              inorder, inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,mp);
        return root;
    }
