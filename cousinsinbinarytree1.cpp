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

int findParentHeight(Node* root,int& parent,int value,int height){
    if(!root){
        return 0;
    }

    if(root->data==value){
        return height;
    }

    parent=root->data;
    int left=findParentHeight(root->left,parent,value,height+1);
    if(left){
        return left;
    }

    parent=root->data;
    int right=findParentHeight(root->right,parent,value,height+1);
    return right;
}

bool areCousins(Node* root,int x,int y){
    if(!root){
        return false;
    }

    if(root->data==x && root->data==y){
        return false;
    }

    int xParent=-1;
    int xHeight=findParentHeight(root,xParent,x,0);

    int yParent=-1;
    int yHeight=findParentHeight(root,yParent,y,0);

    if(xParent!=yParent && xHeight==yHeight){
        return true;
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