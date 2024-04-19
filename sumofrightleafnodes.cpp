#include<iostream>
#include<queue>
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

void solve(Node* root,int& sum){
    if(!root){
        return ;
    }

    if(root->right){
        if(root->right->left==NULL && root->right->right==NULL){
            sum+=root->right->data;
        }
    }

    solve(root->left,sum);
    solve(root->right,sum);
}

int sumOfRightLeafNodes(Node* root){
    int sum=0;
    solve(root,sum);
    return sum;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The sum of right leaf nodes of the Binary Tree is "<<sumOfRightLeafNodes(root)<<endl;

    return 0;
}