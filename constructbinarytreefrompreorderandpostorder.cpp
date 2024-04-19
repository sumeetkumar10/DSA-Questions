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

void levelOrderTraversal(Node* root){
    if(!root){
        return ;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        int size=q.size();
        while(size--){
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
}

int preorderIndex=0;
int postorderIndex=0;
Node* constructTree(int pre[],int post[],int n){
    Node* root=new Node(pre[preorderIndex++]);
    if(root->data!=post[postorderIndex]){
        root->left=constructTree(pre,post,n);
    }
    if(root->data!=post[postorderIndex]){
        root->right=constructTree(pre,post,n);
    }
    postorderIndex++;
    return root;
}

int main(){
    int pre[]={1,2,4,5,3,6,7};
    int post[]={4,5,2,6,7,3,1};
    int n=7;
    Node* ans=constructTree(pre,post,n);
    levelOrderTraversal(ans);

    return 0;
}