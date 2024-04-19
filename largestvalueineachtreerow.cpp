#include<iostream>
#include<queue>
#include<vector>
#include<climits>
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

vector<int> findLargestInEachRow(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        int maxi=INT_MIN;
        for(int i=0;i<size;i++){
            Node* curr=q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            maxi=max(maxi,curr->data);
        }
        ans.push_back(maxi);
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> ans=findLargestInEachRow(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}