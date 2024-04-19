#include<iostream>
#include<map>
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

vector<int> verticalOrderTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<Node*,pair<int,int>> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;

        int horizDist=temp.second.first;
        int level=temp.second.second;

        nodes[horizDist][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(horizDist-1,level+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,make_pair(horizDist+1,level+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The vertical order traversal of the Binary Tree is "<<endl;
    vector<int> ans=verticalOrderTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}