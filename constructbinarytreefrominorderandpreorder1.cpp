#include<iostream>
#include<map>
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

void createMapping(int in[],map<int,int>& nodeToIndex,int n){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}

Node* solve(int in[],int pre[],int& index,int inorderStart,int inorderEnd,int n,map<int,int>& nodeToIndex){
    if(index>n || inorderStart>inorderEnd){
        return NULL;
    }

    int element=pre[index++];
    Node* root=new Node(element);
    int position=nodeToIndex[element];

    root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToIndex);
    root->right=solve(in,pre,index,position+1,inorderEnd,n,nodeToIndex);

    return root;
}

Node* constructTree(int in[],int pre[],int n){
    int preorderIndex=0;
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    return solve(in,pre,preorderIndex,0,n-1,n,nodeToIndex);
}

int main(){
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    int n=6;
    Node* ans=constructTree(in,pre,n);
    levelOrderTraversal(ans);

    return 0;
}