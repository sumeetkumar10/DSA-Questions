#include<iostream>
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

bool solve(Node* root,int targetSum){
    if(root==NULL){
        return false;
    }

    targetSum-=root->data;

    if(targetSum==0 && root->left==NULL && root->right==NULL){
        return true;
    }

    return solve(root->left,targetSum) || solve(root->right,targetSum);
}

bool hasPathSum(Node* root,int targetSum){
    return solve(root,targetSum);
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int targetSum=28;

    if(hasPathSum(root,targetSum)){
        cout<<"Root to Leaf Path is present."<<endl;
    }
    else{
        cout<<"Root to Leaf Path is not present."<<endl;
    }

    return 0;
}