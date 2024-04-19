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

int maxHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    return max(maxHeight(root->left),maxHeight(root->right))+1;
}

int minHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    int left=minHeight(root->left);
    int right=minHeight(root->right);

    if(left==0 || right==0){
        return left+right+1;
    }
    else{
        return min(left,right)+1;
    }
}

bool areLeavesAtSameLevel(Node* root){
    return (maxHeight(root)==minHeight(root));
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(areLeavesAtSameLevel(root)){
        cout<<"Leaves are at the Same Level."<<endl;
    }
    else{
        cout<<"Leaves are not at the Same Level."<<endl;
    }

    return 0;
}