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
    else if(root1==NULL && root2!=NULL){
        return false;
    }
    else if(root1!=NULL && root2==NULL){
        return false;
    }

    bool left=isIdenticalTree(root1->left,root2->left);
    bool right=isIdenticalTree(root1->right,root2->right);

    bool condition=root1->data==root2->data;

    if(left && right && condition){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root1=NULL;

    root1=buildTree(root1);

    Node* root2=NULL;

    root2=buildTree(root2);

    if(isIdenticalTree(root1,root2)){
        cout<<"It is an Identical Tree."<<endl;
    }
    else{
        cout<<"It is not an Identical Tree."<<endl;
    }

    return 0;
}