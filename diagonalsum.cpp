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

vector<int> diagonalSum(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        int sum=0;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            while(temp!=NULL){
                if(temp->left){
                    q.push(temp->left);
                }
                sum+=temp->data;

                temp=temp->right;
            }
        }
        ans.push_back(sum);
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);
    
    vector<int> ans=diagonalSum(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}