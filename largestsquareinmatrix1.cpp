#include<iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int>>& matrix,int& maxi){
    int row=matrix.size();
    int col=matrix[0].size();

    vector<vector<int>> dp(row+1,vector<int>(col+1,0));

    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right=dp[i][j+1];
            int diagonal=dp[i+1][j+1];
            int down=dp[i+1][j];

            if(matrix[i][j]==1){
                dp[i][j]=1+min(right,min(diagonal,down));
                maxi=max(maxi,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return dp[0][0];
}

int maxSquare(vector<vector<int>>& matrix,int n,int m){
    int maxi=0;
    solve(matrix,maxi);
    return maxi;
}

int main(){
    int n=2;
    int m=2;

    vector<vector<int>> matrix={{1,1},{1,1}};

    cout<<"The largest square formed in the matrix is "<<maxSquare(matrix,n,m)<<endl;

    return 0;
}