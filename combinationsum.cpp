#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& candidates,int target,int index,vector<int>& temp,vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(temp);
        return ;
    }

    if(target<0){
        index++;
        return ;
    }

    for(int i=index;i<candidates.size();i++){
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i,temp,ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates,int target){
    vector<int> temp;
    vector<vector<int>> ans;
    solve(candidates,target,0,temp,ans);
    return ans;
}

int main(){
    vector<int> candidates={1,4,8,4};
    int target=9;

    vector<vector<int>> ans=combinationSum(candidates,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}