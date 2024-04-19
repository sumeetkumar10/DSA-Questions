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

void solve(Node* root,string res,vector<string>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        res+=to_string(root->data);
        ans.push_back(res);
        return ;
    }

    res+=to_string(root->data)+"->";

    solve(root->left,res,ans);
    solve(root->right,res,ans);
}

vector<string> printRootToLeafPaths(Node* root){
    vector<string> ans;
    string res="";
    solve(root,res,ans);
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<string> ans=printRootToLeafPaths(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}