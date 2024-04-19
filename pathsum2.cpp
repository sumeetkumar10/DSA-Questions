#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void solve(Node* root,int targetSum,vector<int>& path,vector<vector<int>>& ans){
    if(root==NULL){
        return ;
    }

    path.push_back(root->data);

    if(root->left==NULL && root->right==NULL && root->data==targetSum){
        ans.push_back(path);
    }

    solve(root->left,targetSum-root->data,path,ans);
    solve(root->right,targetSum-root->data,path,ans);

    path.pop_back();
}

vector<vector<int>> pathSum(Node* root,int targetSum){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }

    vector<int> path;
    solve(root,targetSum,path,ans);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int targetSum=27;
    vector<vector<int>> ans=pathSum(root,targetSum);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}