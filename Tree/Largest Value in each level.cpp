class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();   
                if(maxi<front->data) maxi=front->data;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
    
};
