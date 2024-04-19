#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solve(vector<int>& obstacles,int currpos,int currlane,vector<vector<int>>& dp){
    int n=obstacles.size();

    if(currpos==n){
        return 0;
    }

    if(dp[currpos][currlane]!=-1){
        return dp[currpos][currlane];
    }

    if(obstacles[currpos+1]!=currlane){
        return solve(obstacles,currpos+1,currlane,dp);
    }
    else{
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i && obstacles[currpos]!=i){
                ans=min(ans,1+solve(obstacles,currpos,i,dp));
            }
        }
        return dp[currpos][currlane]=ans;
    }
}

int minSidewaysJump(vector<int>& obstacles){
    vector<vector<int>> dp(obstacles.size(),vector<int>(4,-1));
    return solve(obstacles,0,2,dp);
}

int main(){
    // vector<int> obstacles={0,1,1,0,3,3,0};

    vector<int> obstacles={0,2,1,0,3,0};

    cout<<"The minimum number of sideways jump required is "<<minSidewaysJump(obstacles)<<endl;

    return 0;
}