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

bool solve(Node* root,vector<int>& path,int x){
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data==x){
        return true;
    }

    if(solve(root->left,path,x) || solve(root->right,path,x)){
        return true;
    }
    path.pop_back();

    return false;
}

vector<int> rootToNodePath(Node* root,int x){
    vector<int> path;

    if(root==NULL){
        return path;
    }
    solve(root,path,x);
    return path;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int x=4;

    vector<int> ans=rootToNodePath(root,x);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}