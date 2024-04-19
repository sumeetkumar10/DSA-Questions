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

int findBottomLeftValue(Node* root){
    int last=0;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            if(i==0){
                last=temp->data;
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return last;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The bottom left tree value is "<<findBottomLeftValue(root)<<endl;

    return 0;
}