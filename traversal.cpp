#include<iostream>
#include<climits>
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

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    return max(height(root->left),height(root->right))+1;
}

// int diameter(Node* root){
//     if(root==NULL){
//         return 0;
//     }

//     int op1=diameter(root->left);
//     int op2=diameter(root->right);
//     int op3=height(root->left)+height(root->right)+1;

//     return max(op1,max(op2,op3));
// }

pair<int,int> diameterFast(Node* root){
    if(root==NULL){
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> leftAns=diameterFast(root->left);
    pair<int,int> rightAns=diameterFast(root->right);

    int op1=leftAns.first;
    int op2=rightAns.first;
    int op3=leftAns.second+rightAns.second+1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(leftAns.second,rightAns.second)+1;
    return ans;
}

// bool isBalancedTree(Node* root){
//     if(root==NULL){
//         return true;
//     }

//     bool leftAns=isBalancedTree(root->left);
//     bool rightAns=isBalancedTree(root->right);
//     bool diff=abs(height(root->left)-height(root->right))<=1;

//     if(leftAns && rightAns && diff){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

pair<bool,int> isBalancedTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> leftAns=isBalancedTreeFast(root->left);
    pair<bool,int> rightAns=isBalancedTreeFast(root->right);

    bool left=leftAns.first;
    bool right=rightAns.first;
    bool diff=abs(leftAns.second-rightAns.second)<=1;

    pair<bool,int> ans;
    ans.second=max(leftAns.second,rightAns.second)+1;

    if(left && right && diff){
        ans.first=true;    
    }
    else{
        ans.second=true;
    }
    return ans;
}

bool isBalancedTree(Node* root){
    return isBalancedTreeFast(root).first;
}

int diameter(Node* root){
    return diameterFast(root).first;
}

pair<bool,int> isSumTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns=isSumTreeFast(root->left);
    pair<bool,int> rightAns=isSumTreeFast(root->right);

    bool isLeftSumTree=leftAns.first;
    bool isRightSumTree=rightAns.first;

    int leftSum=leftAns.second;
    int rightSum=rightAns.second;

    bool condition=root->data==leftSum+rightSum;

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && condition){
        ans.first=true;
        ans.second=root->data+leftSum+rightSum;
    }
    else{
        ans.first=false;
    }
    return ans;
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first;
}

// bool isSameTree(Node* root1,Node* root2){
//     if(root1==NULL && root2==NULL){
//         return true;
//     }

//     if(root1!=NULL && root2!=NULL){
//         return (root1->data==root2->data) && (isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right));
//     }
//     return false;
// }

bool isSameTree(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1!=NULL && root2!=NULL){
        return root1->data==root2->data && (isSameTree(root1->left,root2->right),isSameTree(root1->right,root2->left));
    }
    return false;
}

bool isSymmetricTree(Node* root){
    return isSameTree(root->left,root->right);
}

void traverseLeft(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return ;
    }

    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

void traverseRight(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        return ;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}

void traverseLeaf(Node* root,vector<int>& ans){
    if(root==NULL){
        return ;
    }

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return ;
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    traverseRight(root->right,ans);

    return ans;
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

vector<int> topView(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    map<int,int> topNode;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;
        int horizDist=temp.second;

        if(topNode.find(horizDist)==topNode.end()){
            topNode[horizDist]=frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,horizDist-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,horizDist+1));
        }
    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    map<int,int> bottomNode;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp=q.front();
        q.pop();

        Node* frontNode=temp.first;
        int horizDist=temp.second;

        bottomNode[horizDist]=frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left,horizDist-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,horizDist+1));
        }
    }
    for(auto i:bottomNode){
        ans.push_back(i.second);
    }
    return ans;
}

void solveLeft(Node* root,int level,vector<int>& ans){
    if(!root){
        return ;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    solveLeft(root->left,level+1,ans);
    solveLeft(root->right,level+1,ans);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    solveLeft(root,0,ans);
    return ans;
}

void solveRight(Node* root,int level,vector<int>& ans){
    if(!root){
        return ;
    }

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    solveRight(root->right,level+1,ans);
    solveRight(root->left,level+1,ans);
}

vector<int> rightView(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    solveRight(root,0,ans);
    return ans;
}

void solveBloodline(Node* root,int len,int& maxLen,int sum,int& maxSum){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen){
            maxSum=max(maxSum,sum);
        }
        return ;
    }

    sum+=root->data;

    solveBloodline(root->left,len+1,maxLen,sum,maxSum);
    solveBloodline(root->right,len+1,maxLen,sum,maxSum);
}

int sumOfLongestBloodline(Node* root){
    int len=0;
    int maxLen=0;

    int sum=0;
    int maxSum=INT_MIN;

    solveBloodline(root,len,maxLen,sum,maxSum);
    return maxSum;
}

Node* lca(Node* root,int p,int q){
    if(!root){
        return NULL;
    }

    if(root->data==p || root->data==q){
        return root;
    }

    Node* leftAns=lca(root->left,p,q);
    Node* rightAns=lca(root->right,p,q);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    if(leftAns==NULL && rightAns==NULL){
        return NULL;
    }
    return (leftAns==NULL)?rightAns:leftAns;
}

Node* solvekthAncestor(Node* root,int node,int& k){
    if(!root){
        return NULL;
    }

    if(root->data==node){
        return root;
    }

    Node* leftAns=solvekthAncestor(root->left,node,k);
    Node* rightAns=solvekthAncestor(root->right,node,k);

    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node* root,int node,int k){
    Node* ans=solvekthAncestor(root,node,k);

    if(!ans || ans->data==k){
        return -1;
    }
    else{
        return ans->data;
    }
}

bool hasPathSum(Node* root,int targetSum){
    if(!root){
        return false;
    }

    targetSum-=root->data;

    if(root->left==NULL && root->right==NULL && targetSum==0){
        return true;
    }

    return (hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum));
}

void solvePathSum(Node* root,int targetSum,vector<int>& path,vector<vector<int>>& ans){
    if(!root){
        return ;
    }

    path.push_back(root->data);

    if(root->left==NULL && root->right==NULL && root->data==targetSum){
        ans.push_back(path);
    }

    solvePathSum(root->left,targetSum-root->data,path,ans);
    solvePathSum(root->right,targetSum-root->data,path,ans);

    path.pop_back();
}

vector<vector<int>> pathSum(Node* root,int targetSum){
    vector<vector<int>> ans;
    vector<int> path;

    solvePathSum(root,targetSum,path,ans);
    return ans;
}

int count=0;
long long int sum=0;
void solvekSumPath(Node* root,int k){
    if(!root){
        return ;
    }

    sum+=root->data;

    if(sum==k){
        count++;
    }

    solvekSumPath(root->left,k);
    solvekSumPath(root->right,k);

    sum-=root->data;
}

int kSumPath(Node* root,int k){
    if(root){
        solvekSumPath(root,k);
        kSumPath(root->left,k);
        kSumPath(root->right,k);
    }
    return count;
}

int solveSubtreeSum(Node* root,int sum,int& count){
    if(!root){
        return 0;
    }

    int left=solveSubtreeSum(root->left,sum,count);
    int right=solveSubtreeSum(root->right,sum,count);

    if(root->data+left+right==sum){
        count++;
    }
    return root->data+left+right;
}

int countSubtreesWithGivenSum(Node* root,int sum){
    int count=0;
    solveSubtreeSum(root,sum,count);
    return count;
}

int main(){
    Node* root=NULL;

    root=buildTree(root);

    cout<<"The height of the Binary Tree is "<<height(root)<<endl;

    cout<<"The diameter of the Binary Tree is "<<diameter(root)<<endl;

    if(isBalancedTree(root)){
        cout<<"The Binary Tree is balanced."<<endl;
    }
    else{
        cout<<"The Binary Tree is not balaned."<<endl;
    }

    if(isSumTree(root)){
        cout<<"The Binary Tree is a sum tree."<<endl;
    }
    else{
        cout<<"The Binary Tree us not a sum tree."<<endl;
    }

    // Node* root1=NULL;

    // root1=buildTree(root1);

    // Node* root2=NULL;

    // root2=buildTree(root2);

    // if(isSameTree(root1,root2)){
    //     cout<<"Both are Same Trees."<<endl;
    // }
    // else{
    //     cout<<"Both Trees are not Same."<<endl;
    // }

    if(isSymmetricTree(root)){
        cout<<"Both are Symmetric Trees."<<endl;
    }
    else{
        cout<<"Both Trees are not Symmetric."<<endl;
    }

    cout<<"The boundary traversal of the Binary Tree is "<<endl;
    vector<int> boundaryAns=boundaryTraversal(root);
    for(int i=0;i<boundaryAns.size();i++){
        cout<<boundaryAns[i]<<" ";
    }
    cout<<endl;

    cout<<"The vertical traversal of the Binary Tree is "<<endl;
    vector<int> verticalAns=verticalOrderTraversal(root);
    for(int i=0;i<verticalAns.size();i++){
        cout<<verticalAns[i]<<" ";
    }
    cout<<endl;

    cout<<"The top view of the Binary Tree is "<<endl;
    vector<int> topAns=topView(root);
    for(int i=0;i<topAns.size();i++){
        cout<<topAns[i]<<" ";
    }
    cout<<endl;

    cout<<"The bottom view of the Binary Tree is "<<endl;
    vector<int> bottomAns=bottomView(root);
    for(int i=0;i<bottomAns.size();i++){
        cout<<bottomAns[i]<<" ";
    }
    cout<<endl;

    cout<<"The left view of the Binary Tree is "<<endl;
    vector<int> leftAns=leftView(root);
    for(int i=0;i<leftAns.size();i++){
        cout<<leftAns[i]<<" ";
    }
    cout<<endl;

    cout<<"The right view of the Binary Tree is "<<endl;
    vector<int> rightAns=rightView(root);
    for(int i=0;i<rightAns.size();i++){
        cout<<rightAns[i]<<" ";
    }
    cout<<endl;

    cout<<"The sum of the longest bloodline in the Binary Tree is "<<sumOfLongestBloodline(root)<<endl;

    int p=5;
    int q=1;
    cout<<"The lowest common ancestor of "<<p<<" and "<<q<<" in the Binary Tree is "<<lca(root,p,q)->data<<endl;

    // int k=3;
    // int node=6;
    // cout<<k<<"th Ancestor of "<<node<<" in the Binary Tree is "<<kthAncestor(root,node,k)<<endl;

    int targetSum=13;
    if(hasPathSum(root,targetSum)){
        cout<<"Root to leaf path is present."<<endl;
    }
    else{
        cout<<"Root to leaf path is not present."<<endl;
    }

    vector<vector<int>> pathSumAns=pathSum(root,targetSum);
    for(auto i:pathSumAns){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    int k=13;
    cout<<"The Number of Paths with "<<k<<" sum is "<<kSumPath(root,k)<<endl;

    int sum=7;
    cout<<"The number of subtrees with sum = "<<sum<<" is "<<countSubtreesWithGivenSum(root,sum)<<endl;

    return 0;
}