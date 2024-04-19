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

void solve(Node* root,int& maxi,int& mini){
    if(!root){
        return ;
    }

    if(root->data>=maxi){
        maxi=root->data;
    }

    if(root->data<=mini){
        mini=root->data;
    }

    solve(root->left,maxi,mini);
    solve(root->right,maxi,mini);
}

int findMax(Node* root){
    int maxi=INT_MIN;
    int mini=INT_MAX;
    solve(root,maxi,mini);
    return maxi;
}

int findMin(Node* root){
    int maxi=INT_MIN;
    int mini=INT_MAX;
    solve(root,maxi,mini);
    return mini;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The maximum element in the Binary Tree is "<<findMax(root)<<endl;

    cout<<"The minimum element in the Binary Tree is "<<findMin(root)<<endl;

    return 0;
}