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

vector<int> verticalSum(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    map<int,int> nodes;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;
        int horizDist=temp.second;

        nodes[horizDist]+=frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,horizDist-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,horizDist+1));
        }
    }
    for(auto i:nodes){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);
    
    vector<int> ans=verticalSum(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}