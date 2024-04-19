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

pair<bool,int> isBalancedTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left=isBalancedTreeFast(root->left);
    pair<bool,int> right=isBalancedTreeFast(root->right);

    bool isLeftTreeBalanced=left.first;
    bool isRightTreeBalanced=right.first;

    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(isLeftTreeBalanced && isRightTreeBalanced && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isBalancedTree(Node* root){
    return isBalancedTreeFast(root).first;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    if(isBalancedTree(root)){
        cout<<"It is a balanced Binary Tree."<<endl;
    }
    else{
        cout<<"It is not a balanced Binary Tree."<<endl;
    }

    return 0;
}