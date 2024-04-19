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

Node* lca(Node* root,int p,int q){
    if(root==NULL){
        return NULL;
    }

    if(root->data==p || root->data==q){
        return root;
    }

    Node* leftAns=lca(root->left,p,q);
    Node* rightAns=lca(root->right,p,q);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else{
        return NULL;
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int p=39;
    int q=51;

    cout<<"The Lowest Common Ancestor of "<<p<<" and "<<q<<" is "<<lca(root,p,q)->data<<endl;

    return 0;
}