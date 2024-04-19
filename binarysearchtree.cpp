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

Node* insertIntoBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(root->data>data){
        root->left=insertIntoBST(root->left,data);
    }
    else{
        root->right=insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
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

void inorder(Node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool searchInBST(Node* root,int target){
    if(root==NULL){
        return false;
    }

    if(root->data==target){
        return true;
    }

    if(root->data>target){
        return searchInBST(root->left,target);
    }
    else{
        return searchInBST(root->right,target);
    }
}

int minVal(Node* root){
    Node* temp=root;

    if(temp==NULL){
        return -1;
    }

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int maxVal(Node* root){
    Node* temp=root;

    if(temp==NULL){
        return -1;
    }

    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

int main(){
    Node* root=NULL;

    takeInput(root);
    levelOrderTraversal(root);

    cout<<"Inorder Traversal of the BST is "<<endl;
    inorder(root);

    cout<<endl;
    cout<<"Preorder Traversal of the BST is "<<endl;
    preorder(root);

    cout<<endl;
    cout<<"Postorder Traversal of the BST is "<<endl;
    postorder(root);

    cout<<endl;
    int target=81;
    if(searchInBST(root,target)){
        cout<<target<<" is Present in The BST."<<endl;
    }
    else{
        cout<<target<<" is not Present in The BST."<<endl;
    }

    cout<<"Minimum Value in the BST is "<<minVal(root)<<endl;

    cout<<"Maximum Value in the BST is "<<maxVal(root)<<endl;

    return 0;
}