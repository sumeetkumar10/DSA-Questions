#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>& obstacles){
    int n=obstacles.size()-1;

    vector<int> curr(4,INT_MAX);
    vector<int> next(4,INT_MAX);

    next[0]=0;
    next[1]=0;
    next[2]=0;
    next[3]=0;

    for(int currpos=n-1;currpos>=0;currpos--){
        for(int currlane=1;currlane<=3;currlane++){
            if(obstacles[currpos+1]!=currlane){
                curr[currlane]=next[currlane];
            }
            else{
                int ans=INT_MAX;
                for(int i=1;i<=3;i++){
                    if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans,1+next[i]);
                }
            }
            curr[currlane]=ans;
            }
        }
        next=curr;
    }
    return min(next[2],min(1+next[1],1+next[3]));
}

int minJump(vector<int> obstacles){
    return solve(obstacles);
}

int main(){
    vector<int> obstacles={0,1,1,2,3,1,3};

    cout<<"The minimum number of sideways jump is "<<minJump(obstacles)<<endl;

    return 0;
}