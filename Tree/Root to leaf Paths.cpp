 void leafPath(Node* root,vector<vector<int>> &ans,vector<int> temp){
     if(root==NULL){
         return;
     };
     temp.push_back(root->data);
     if(root->left==NULL && root->right==NULL) ans.push_back(temp);
     leafPath(root->left,ans,temp);
     leafPath(root->right,ans,temp);
 }
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    vector<int> temp;
    leafPath(root,ans,temp);
    return ans;
}
