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

bool linearSearch(vector<int>& arr,int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

bool areCousins(Node* root,int x,int y){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            if(temp->left && temp->right){
                if(temp->left->data==x && temp->right->data==y){
                    return false;
                }
                if(temp->right->data==x && temp->left->data==y){
                    return false;
                }
            }
            level.push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(linearSearch(level,level.size(),x) && linearSearch(level,level.size(),y)){
            return true;
        }
    }
    return false;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    int x=9;
    int y=30;
    if(areCousins(root,x,y)){
        cout<<"Yes "<<x<<" and "<<y<<" are cousins."<<endl;
    }
    else{
        cout<<"No "<<x<<" and "<<y<<" are not cousins."<<endl;
    }

    return 0;
}