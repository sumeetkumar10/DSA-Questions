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

int solve(Node* root,int X,int& count){
    if(!root){
        return 0;
    }

    int left=solve(root->left,X,count);
    int right=solve(root->right,X,count);

    if(root->data+left+right==X){
        count++;
    }
    return root->data+left+right;
}

int countSubtreesWithGivenSum(Node* root,int X){
    int count=0;
    solve(root,X,count);
    return count;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int X=7;

    cout<<"The number of Subtrees with Sum = "<<X<<" is "<<countSubtreesWithGivenSum(root,X)<<endl;
    
    return 0;
}