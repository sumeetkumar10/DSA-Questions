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

int kthLargestSumInBinaryTree(Node* root,int k){
    if(root==NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);

    priority_queue<int,vector<int>,greater<int>> pq;

    while(!q.empty()){
        int size=q.size();
        int sum=0;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            sum+=temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        pq.push(sum);
        if(pq.size()>k){
            pq.pop();
        }
    }
    if(pq.size()<k){
        return -1;
    }
    return pq.top();
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int k=1;

    cout<<k<<"th Largest value in the Binary Tree is "<<kthLargestSumInBinaryTree(root,k)<<endl;

    return 0;
}