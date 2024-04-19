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

    cout<<"Enter the data for inserting in thr left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in thr right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

Node* deleteLeavesWithGivenValue(Node* root,int target){
    if(root->left!=NULL){
        root->left=deleteLeavesWithGivenValue(root->left,target);
    }
    if(root->right!=NULL){
        root->right=deleteLeavesWithGivenValue(root->right,target);
    }

    return root->left==root->right && root->data==target ? NULL : root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    levelOrderTraversal(root);

    int target;
    cin>>target;

    Node* ans=deleteLeavesWithGivenValue(root,target);
    levelOrderTraversal(ans);

    return 0;
}