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

Node* solve(int in[],int pre[],int& index,int inorderStart,int inorderEnd,int n){
    if(index>n || inorderStart>inorderEnd){
        return NULL;
    }

    int element=pre[index++];
    Node* root=new Node(element);
    int position=findPosition(in,element,n);

    root->left=solve(in,pre,index,inorderStart,position-1,n);
    root->right=solve(in,pre,index,position+1,inorderEnd,n);

    return root;
}

Node* constructTree(int in[],int pre[],int n){
    int preorderIndex=0;
    return solve(in,pre,preorderIndex,0,n-1,n);
}

int main(){
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    int n=6;
    Node* ans=constructTree(in,pre,n);
    levelOrderTraversal(ans);

    return 0;
}