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

void solve(Node* root1,Node* root2,int index){
    if(!root1 || !root2){
        return ;
    }

    if(index%2==0){
        swap(root1->data,root2->data);
    }

    solve(root1->left,root2->right,index+1);
    solve(root1->right,root2->left,index+1);
}

void reverseAlternateLevels(Node* root){
    solve(root->left,root->right,0);
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
    reverseAlternateLevels(root);
    levelOrderTraversal(root);

    return 0;
}