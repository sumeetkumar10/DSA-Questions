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

void solve(Node* root,int len,int& maxLen,int sum,int& maxSum){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        if(len==maxLen){
            maxSum=max(maxSum,sum);
        }
        return ;
    }

    sum+=root->data;

    solve(root->left,len+1,maxLen,sum,maxSum);
    solve(root->right,len+1,maxLen,sum,maxSum);
}

int sumOfLongestBloodline(Node* root){
    int len=0;
    int maxLen=0;

    int sum=0;
    int maxSum=0;

    solve(root,len,maxLen,sum,maxSum);
    return maxSum;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The sum of the Longest bloodline is "<<sumOfLongestBloodline(root)<<endl;

    return 0;
}