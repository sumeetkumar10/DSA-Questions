#include<iostream>
#include<climits>
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

int solve(Node* root,int maxi,int& res){
    if(root==NULL){
        return 0;
    }

    if(root->data>=maxi){
        res++;
        maxi=root->data;
    }

    solve(root->left,maxi,res);
    solve(root->right,maxi,res);

    return res;
}

int countGoodNodes(Node* root){
    int res=0;
    return solve(root,INT_MIN,res);
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"There are "<<countGoodNodes(root)<<" good nodes in the Binary Tree."<<endl;

    return 0;
}