#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>& matrix,int i,int j,int& maxi,vector<vector<int>>& dp){
    if(i>=matrix.size() || j>=matrix[0].size()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int right=solve(matrix,i,j+1,maxi,dp);
    int diagonal=solve(matrix,i+1,j+1,maxi,dp);
    int down=solve(matrix,i+1,j,maxi,dp);

    if(matrix[i][j]==1){
        int ans=1+min(right,min(diagonal,down));
        maxi=max(maxi,ans);
        return dp[i][j]=ans;
    }
    else{
        return dp[i][j]=0;
    }
}

int maxSquare(vector<vector<int>>& matrix,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int maxi=0;
    solve(matrix,0,0,maxi,dp);
    return maxi;
}

int main(){
    int n=2;
    int m=2;

    vector<vector<int>> matrix={{1,1},{1,1}};

    cout<<"The largest square formed in the matrix is "<<maxSquare(matrix,n,m)<<endl;

    return 0;
}