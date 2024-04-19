#include<iostream>
#include<queue>
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

    cout<<"Enter the data for inserting in thr left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in thr right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

Node* addOneRow(Node* root,int val,int depth){
    if(depth==1){
        Node* temp=new Node(val);
        temp->left=root;
        return temp;
    }

    queue<Node*> q;
    q.push(root);

    int level=2;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* root1=q.front();
            q.pop();
            if(level==depth){
                if(root1->left!=NULL){
                    Node* temp=new Node(val);
                    temp->left=root1->left;
                    root1->left=temp;
                }
                if(root->right!=NULL){
                    Node* temp=new Node(val);
                    temp->right=root1->right;
                    root1->right=temp;
                }
                if(root1->left==NULL){
                    Node* temp=new Node(val);
                    root1->left=temp;
                }
                if(root1->right==NULL){
                    Node* temp=new Node(val);
                    root1->right=temp;
                }
            }
            else{
                if(root1->left!=NULL){
                    q.push(root1->left);
                }
                if(root1->right!=NULL){
                    q.push(root1->right);
                }
            }
            level++;
        }
    }
    return root;
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

int main(){
    Node* root=NULL;

    root=buildTree(root);

    levelOrderTraversal(root);

    int val;
    cin>>val;

    int depth;
    cin>>depth;

    Node* ans=addOneRow(root,val,depth);
    levelOrderTraversal(ans);

    return 0;
}