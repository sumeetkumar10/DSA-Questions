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

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}

bool isBalancedTree(Node* root){
    if(root==NULL){
        return true;
    }

    bool isLeftBalanced=isBalancedTree(root->left);
    bool isRightBalanced=isBalancedTree(root->right);

    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(isLeftBalanced && isRightBalanced && diff){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isBalancedTree(root)){
        cout<<"It is a balanced Binary Tree."<<endl;
    }
    else{
        cout<<"It is not a balanced Binary Tree."<<endl;
    }

    return 0;
}