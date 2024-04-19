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

int sumOfNodesAtMinLevel(Node* root){
    queue<Node*> q;
    q.push(root);

    int sum=0;
    while(!q.empty()){
        int size=q.size();
        bool flag=true;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            if(temp->left==NULL && temp->right==NULL){
                sum+=temp->data;
                flag=false;
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(flag==false){
            break;
        }
    }
    return sum;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The sum of the nodes at the Min Level is "<<sumOfNodesAtMinLevel(root)<<endl;

    return 0;
}