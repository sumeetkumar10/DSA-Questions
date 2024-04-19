#include<iostream>
#include<vector>
using namespace std;

int solve(string str1,string str2,int n,int m,vector<vector<int>>& dp){
    if(n==0 || m==0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        return dp[n][m]=1+solve(str1,str2,n-1,m-1,dp);
    }
    else{
        return dp[n][m]=max(solve(str1,str2,n,m-1,dp),solve(str1,str2,n-1,m,dp));
    }
}

int lcs(string str1,string str2){
    int n=str1.length();
    int m=str2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return solve(str1,str2,n,m,dp);
}

int main(){
    string str1="abc";
    string str2="def";

    cout<<"The Longest Consecutive sequence of "<<str1<<" and "<<str2<<" is "<<lcs(str1,str2);

    return 0;
}