#include<iostream>
#include<vector>
using namespace std;

void printSolutions(vector<vector<char>>& board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(vector<vector<char>>& board,int n,int row,int col){
    int i=row;
    int j=col;

    //Row
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }

    i=row;
    j=col;
    //Upper Left Diagonal
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    i=row;
    j=col;
    //Bottom Left Diagonal
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<char>>& board,int n,int col){
    if(col>=n){                                                     //if(col==n)
        printSolutions(board,n);
        return ;
    }

    for(int row=0;row<n;row++){
        if(isSafe(board,n,row,col)){
            board[row][col]='Q';
            solve(board,n,col+1);
            board[row][col]='-';
        }
    }
}

int main(){
    int n=4;
    vector<vector<char>> board(n,vector<char>(n,'-'));

    solve(board,n,0);

    return 0;
}