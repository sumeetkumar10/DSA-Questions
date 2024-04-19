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
    return (!root)?0:max(height(root->left),height(root->right))+1;
}

int solve(Node* root,int h,int start){
    if(!root) return 0;

    if(start==h) return root->data;

    return solve(root->left,h,start+1)+solve(root->right,h,start+1);
}

int deepSum(Node* root){
    return solve(root,height(root),1);
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The Deepest leaves Sum is "<<deepSum(root)<<endl;

    return 0;
}