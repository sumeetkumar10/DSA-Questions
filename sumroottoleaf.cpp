#include<bits/stdc++.h>
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

void solve(Node* root,int& ans,int& num){
    if(root==NULL){
        return ;
    }

    num=num*10+root->data;

    solve(root->left,ans,num);
    solve(root->right,ans,num);

    if(root->left==NULL && root->right==NULL){
        ans+=num;
    }
    num/=10;
}

int sumRootToLeaf(Node* root){
    if(root==NULL){
        return 0;
    }

    int ans=0;
    int num=0;

    solve(root,ans,num);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The sum of root to leaf is "<<sumRootToLeaf(root)<<endl;

    return 0;
}