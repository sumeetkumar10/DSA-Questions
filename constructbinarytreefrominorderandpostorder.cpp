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

int findPosition(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int post[],int& index,int inorderStart,int inorderEnd,int n){
    if(index<0 || inorderStart>inorderEnd){
        return NULL;
    }

    int element=post[index--];
    Node* root=new Node(element);
    int position=findPosition(in,element,n);

    root->right=solve(in,post,index,position+1,inorderEnd,n);
    root->left=solve(in,post,index,inorderStart,position-1,n);

    return root;
}

Node* constructTree(int in[],int post[],int n){
    int postorderIndex=n-1;
    return solve(in,post,postorderIndex,0,n-1,n);
}

int main(){
    int in[]={9,3,15,20,7};
    int post[]={3,9,20,15,7};
    int n=5;
    Node* ans=constructTree(in,post,n);
    levelOrderTraversal(ans);

    return 0;
}