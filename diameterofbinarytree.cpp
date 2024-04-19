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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    return max(leftHeight,rightHeight)+1;
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;

    return max(op1,max(op2,op3));
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The diameter of the Binary Tree is "<<diameter(root)<<endl;

    return 0;
}