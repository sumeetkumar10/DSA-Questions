#include<iostream>
#include<vector>
using namespace std;

void solve(int n,int open,int close,string output,vector<string>& ans){
    if(open==0 && close==0){
        ans.push_back(output);
        return ;
    }

    if(open>0){
        output.push_back('(');
        solve(n,open-1,close,output,ans);
        output.pop_back();
    }
    if(close>open){
        output.push_back(')');
        solve(n,open,close-1,output,ans);
        output.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    string output="";
    solve(n,n,n,output,ans);
    return ans;
}

int main(){
    int n=3;
    vector<string> ans=generateParenthesis(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}