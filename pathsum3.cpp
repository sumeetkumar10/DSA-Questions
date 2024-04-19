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

int count=0;
void solve(Node* root,int targetSum,long long int sum){
    if(root==NULL){
        return ;
    }

    sum+=root->data;

    if(sum==targetSum){
        count++;
    }

    solve(root->left,targetSum,sum);
    solve(root->right,targetSum,sum);
    
    sum-=root->data;
}

int countPathSum(Node* root,int targetSum){
    if(root==NULL){
        return 0;
    }

    long long int sum=0;

    solve(root,targetSum,sum);

    countPathSum(root->left,targetSum);
    countPathSum(root->right,targetSum);

    return count;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int targetSum=8;
    cout<<"There are "<<countPathSum(root,targetSum)<<" paths with "<<targetSum<<" sum in the Binary Tree."<<endl;

    return 0;
}