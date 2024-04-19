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

void solve(Node* root,int target,vector<int>& ans,bool& flag){
    if(!root){
        return ;
    }

    if(root->data==target){
        flag=true;
        return ;
    }

    if(root->left && !flag){
        solve(root->left,target,ans,flag);
    }
    if(root->right && !flag){
        solve(root->right,target,ans,flag);
    }

    if(flag){
        ans.push_back(root->data);
    }
}

vector<int> ancestors(Node* root,int target){
    vector<int> ans;
    if(!root){
        return ans;
    }

    bool flag=false;
    solve(root,target,ans,flag);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int target=99;
    vector<int> ans=ancestors(root,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}