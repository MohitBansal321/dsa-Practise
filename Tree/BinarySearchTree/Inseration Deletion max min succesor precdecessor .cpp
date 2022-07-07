#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};
node* insertIntoBST(node* root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(root->data<data){
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left=insertIntoBST(root->left,data);
        
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void lvlTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void* takeInput(node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}
node* getsuccesor(node* curr){
    curr=curr->right;
    while (curr!=NULL && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
node* getpreccedor(node* curr){
    if(curr->left!=NULL){
        node* tmp=curr->left;
        while(tmp->right){
            tmp=tmp->right;
        }
        return tmp;
    }
}
node* minVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* deleteFromBST(node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child case
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
                node* temp=root->left;
                delete root;
                return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    if(root->data<val){
        root->right=deleteFromBST(root->right,val);
        return root;
    }
    if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
}
int main(){
    node* root=NULL;
    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);
    cout<<"printing the BST"<<endl;
    inorder(root);
    lvlTraversal(root);
    cout<<"succesor"<<endl;
    cout<<getsuccesor(root->right)->data<<endl;
    cout<<"predecessor"<<endl;
    cout<<getpreccedor(root)->data<<endl;  
    deleteFromBST(root,8);
    cout<<"printing the BST"<<endl;
    inorder(root);
    return 0;
}
