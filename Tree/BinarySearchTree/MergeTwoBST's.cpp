//approach 1 tc 0(m+n)  sc 0(m+n)
void inorder(TreeNode<int>* root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> mergeTwovector(vector<int> &ans1,vector<int> &ans2){
    int i=0,j=0,index=0;
    vector<int> ans(ans1.size()+ans2.size());
    while(i<ans1.size() && j<ans2.size()){
        if(ans1[i]<ans2[j]){
            ans[index++]=ans1[i++];
        }
        else{
            ans[index++]=ans2[j++];
        }
    }
    while(i<ans1.size()){
        ans[index++]=ans1[i++];
    }
    while(j<ans2.size()){
        ans[index++]=ans2[j++];
    }
    return ans;
}
TreeNode<int>* inorderToBST(int s,int e,vector<int>&ans){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(ans[mid]);
    root->left=inorderToBST(s,mid-1,ans);
    root->right=inorderToBST(mid+1,e,ans);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    //step 1 inorder save
    vector<int> ans1;
    vector<int> ans2;
    inorder(root1,ans1);
    inorder(root2,ans2);
    vector<int> ans=mergeTwovector(ans1,ans2);
    int s=0,e=ans.size()-1;
    return inorderToBST(s,e,ans);
}

//approach 2
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void convertIntoSortedDLL(TreeNode<int> *root,TreeNode<int> *&head){
    if(root==NULL){
        return ;
    }
    convertIntoSortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoSortedDLL(root->left,head);
}
TreeNode<int>* mergeLinkedList(TreeNode<int> *head1,TreeNode<int>* head2){
    TreeNode<int> *head=NULL;
    TreeNode<int> *tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data <head2->data){
            if(head1==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head2==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
    }
}
int countNodes(TreeNode<int> *head){
    TreeNode<int> *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}
TreeNode<int> *sortedLLToBST(TreeNode<int>* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode<int>* left=sortedLLToBST(head,n/2);
    TreeNode<int>* root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLToBST(head,n-n/2-1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    TreeNode<int> *head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left=NULL;
    TreeNode<int> *head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left=NULL;  
    TreeNode<int>* head=mergeLinkedList(head1,head2);
    return sortedLLToBST(head,countNodes(head));
    
}
