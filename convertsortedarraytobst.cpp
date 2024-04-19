#include<iostream>
#include<queue>
#include<vector>
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

Node* insertIntoBST(Node* root,int data){
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

void takeInput(Node* root){
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

Node* solve(vector<int>& arr,int start,int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        Node* root=new Node(arr[mid]);
        root->left=solve(arr,start,mid-1);
        root->right=solve(arr,mid+1,end);
        return root;
    }
    return NULL;
}

Node* convertSortedArrayToBST(vector<int>& arr){
    return solve(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr={-10,-3,0,5,9};

    Node* ans=convertSortedArrayToBST(arr);
    levelOrderTraversal(ans);

    return 0;
}