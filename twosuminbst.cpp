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

void inorder(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

bool isTwoSum(Node* root,int targetSum){
    vector<int> ans;
    inorder(root,ans);

    int i=0;
    int j=ans.size()-1;

    while(i<j){
        int sum=ans[i]+ans[j];

        if(sum==targetSum){
            return true;
        }
        else if(sum>targetSum){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    Node* root=NULL;

    takeInput(root);

    int targetSum=18;
    if(isTwoSum(root,targetSum)){
        cout<<"Yes Two Sum is present."<<endl;
    }
    else{
        cout<<"No Two Sum is not present."<<endl;
    }

    return 0;
}