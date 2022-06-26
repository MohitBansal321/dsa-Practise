 void createMapping(int in[],map<int,int> &nodeIndex,int n){
        for(int i=0;i<n;i++){
            nodeIndex[in[i]]=i;
        }
    }
Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,
                map<int,int> &nodeIndex){
                if(index <0 || inorderStart>inorderEnd){
                    return NULL;
                }
                int element=post[index--];
                Node* root=new Node(element);
                int position=nodeIndex[element];
                
                root->right=solve(in,post,index,position+1,inorderEnd,n,nodeIndex);
                root->left=solve(in,post,index,inorderStart,position-1,n,nodeIndex);
                return root;
            }
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex=n-1;
        map<int,int> nodeIndex;
        createMapping(in,nodeIndex,n);
        Node *ans=solve(in,post,postOrderIndex,0,n-1,n,nodeIndex);
        return ans;
}
