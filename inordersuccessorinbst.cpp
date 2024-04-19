#include<iostream>
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

Node* insert(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(root->data>data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data!=-1){
        root=insert(root,data);
        cin>>data;
    }
}

vector<int> inorder(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);

    return ans;
}

int inorderSuccessor(Node* root,int key){
    if(root==NULL){
        return -1;
    }

    vector<int> ans=inorder(root);

    if(ans[ans.size()-1]==key){
        return -1;
    }
    
    int res;
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]==key){
            res=ans[i+1];
        }
    }
    return res;
}

int main(){
    Node* root=NULL;

    takeInput(root);

    int key=93;

    cout<<"Inorder Successor of "<<key<<" in BST is "<<inorderSuccessor(root,key)<<endl;

    vector<int> ans=inorder(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}