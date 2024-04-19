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

void solve(Node* root,int level,int& maxlevel,int& ans){
    if(level>maxlevel){
        ans=root->data;
        maxlevel=level;
    }

    if(root->left) solve(root->left,level+1,maxlevel,ans);
    if(root->right) solve(root->right,level+1,maxlevel,ans);
}

int findBottomLeftValue(Node* root){
    int maxlevel=-1,ans=-1;
    solve(root,0,maxlevel,ans);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The Bottom Left value in the tree is "<<findBottomLeftValue(root)<<endl;

    return 0;
}