#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left=NULL;
        Node* right=NULL;

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

bool solve(Node* root,bool& flag,int num){
    if(root==NULL){
        return true;
    }

    if(root->data!=num){
        flag=false;
    }

    return solve(root->left,flag,num) && solve(root->right,flag,num);
}

bool isUnivalued(Node* root){
    bool flag=true;
    int num=root->data;
    solve(root,flag,num);
    return flag;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isUnivalued(root)){
        cout<<"The tree is univalued."<<endl;
    }
    else{
        cout<<"The tree is not univalued."<<endl;
    }

    return 0;
}