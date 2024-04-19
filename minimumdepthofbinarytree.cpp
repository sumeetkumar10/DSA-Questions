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

int minDepth(Node* root){
    if(!root){
        return 0;
    }

    int left=minDepth(root->left);
    int right=minDepth(root->right);

    if(left==0 || right==0){
        return 1+left+right;
    }
    else{
        return min(left,right)+1;
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The minimum depth of the Binary Tree is "<<minDepth(root)<<endl;

    return 0;
}