#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>>& M,int a,int b,int n){
    if(M[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}

int findCelebrity(vector<vector<int>>& M,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }

    while(st.size()>1){
        int a=st.top();
        st.pop();

        int b=st.top();
        st.pop();

        if(knows(M,a,b,n)){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int ans=st.top();

    bool rowCheck=false;
    int zeroCount=0;

    for(int i=0;i<n;i++){
        if(M[ans][i]==0){
            zeroCount++;
        }
    }

    if(zeroCount==n){
        rowCheck=true;
    }

    bool colCheck=false;
    int oneCount=0;

    for(int i=0;i<n;i++){
        if(M[i][ans]==1){
            oneCount++;
        }
    }

    if(oneCount==n-1){
        colCheck=true;
    }

    if(rowCheck && colCheck){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    int n=3;

    vector<vector<int>> M={{0,1,0},{0,0,0},{0,1,0}};

    cout<<findCelebrity(M,n)<<" Is The Celebrity."<<endl;

    return 0;
}