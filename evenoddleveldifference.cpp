#include<iostream>
#include<queue>
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

int evenOddDifference(Node* root){
    if(root==NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    int level=1;
    int evenSum=0,oddSum=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            if(level%2==0){
                evenSum+=temp->data;
            }
            else{
                oddSum+=temp->data;
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        level++;
    }
    return evenSum-oddSum;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The difference between the even level and the odd level of the Binary Tree is "<<evenOddDifference(root)<<endl;

    return 0;
}