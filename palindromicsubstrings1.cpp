#include<iostream>
using namespace std;

int expandAroundIndex(string str,int i,int j){
    int count=0;
    while(i>=0 && j<str.length() && str[i]==str[j]){
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string str){
    int n=str.length();
    int count=0;
    for(int i=0;i<n;i++){
        int oddAns=expandAroundIndex(str,i,i);
        count+=oddAns;

        int evenAns=expandAroundIndex(str,i,i+1);
        count+=evenAns;
    }
    return count;
}

int main(){
    string str="racecar";

    cout<<"The number of Palindromic Substrings in the string is "<<countSubstrings(str)<<"."<<endl;

    return 0;
}