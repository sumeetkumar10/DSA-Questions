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

bool isIdenticalTree(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1 && root2 && root1->data==root2->data){
        return ((isIdenticalTree(root1->left,root2->right)) && isIdenticalTree(root1->right,root2->left));
    }
    return false;
}

bool isSymmetricTree(Node* root){
    return isIdenticalTree(root,root);
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isSymmetricTree(root)){
        cout<<"It is a Symmetric Tree."<<endl;
    }
    else{
        cout<<"It is not a Symmetric Tree."<<endl;
    }

    return 0;
}