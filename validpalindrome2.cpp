#include<iostream>
using namespace std;

bool isPalindrome(string str,int start,int end){
    while(start<=end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool validPalindrome(string str){
    int start=0;
    int end=str.length()-1;

    while(start<=end){
        if(str[start]!=str[end]){
            return isPalindrome(str,start,end-1) || isPalindrome(str,start+1,end);
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    string str="abdca";

    if(validPalindrome(str)){
        cout<<"The string will be a valid palindrome After removeing at Most one character."<<endl;
    }
    else{
        cout<<"The string will not be a valid palindrome After removeing at Most one character."<<endl;
    }
    
    return 0;
}