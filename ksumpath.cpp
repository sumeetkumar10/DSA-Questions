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

void solve(Node* root,int k,int& count,vector<int>& path){
    if(root==NULL){
        return ;
    }

    path.push_back(root->data);

    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    int sum=0;
    for(int i=path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}

int kSumPaths(Node* root,int k){
    int count=0;
    vector<int> path;

    solve(root,k,count,path);
    return count;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int k=5;

    cout<<"There are "<<kSumPaths(root,k)<<" paths with a sum of "<<k<<" in the Binary Tree."<<endl;

    return 0;
}