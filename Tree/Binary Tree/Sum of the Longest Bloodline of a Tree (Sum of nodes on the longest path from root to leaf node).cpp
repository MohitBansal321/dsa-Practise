class Solution
{
    void solve(Node* root,int sum,int &maxSum,int len,int &maxLength){
        if(root==NULL){
            if(len>maxLength){
                maxLength=len;
                maxSum=sum;
            }
            else if(len==maxLength){
                maxSum=max(sum,maxSum);
            }
            return;
        }
        sum=sum+root->data;
        solve(root->left,sum,maxSum,len+1,maxLength);
        solve(root->right,sum,maxSum,len+1,maxLength);
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len=0;
        int maxLength=0;
        int sum=0;
        int maxSum=INT_MIN;
        solve(root,sum,maxSum,len,maxLength);
        return maxSum;
    }
};
