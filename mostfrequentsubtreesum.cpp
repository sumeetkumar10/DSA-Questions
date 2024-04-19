#include<iostream>
#include<unordered_map>
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

int solve(Node* root,int& count,unordered_map<int,int>& mp){
    if(root==NULL){
        return 0;
    }

    int left=solve(root->left,count,mp);
    int right=solve(root->right,count,mp);

    int targetSum=root->data+left+right;
    count=max(count,++mp[targetSum]);

    return targetSum;
}

vector<int> mostFrequentSubtreeSum(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    unordered_map<int,int> mp;
    int count=-1;
    solve(root,count,mp);

    for(auto it:mp){
        if(it.second==count){
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    vector<int> ans=mostFrequentSubtreeSum(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}