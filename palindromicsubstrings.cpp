#include<iostream>
using namespace std;

bool checkPalindrome(string str,int i,int j){
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int countSubstrings(string str){
    int n=str.length();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(checkPalindrome(str,i,j)){
                count++;
            }
        }
    }    
    return count;
}

int main(){
    string str="racecar";

    cout<<"The number of Palindromic Substrings in the string is "<<countSubstrings(str)<<"."<<endl;

    return 0;
}