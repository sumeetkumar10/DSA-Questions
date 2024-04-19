#include<iostream>
using namespace std;

string reverseOnlyLetters(string str){
    int start=0;
    int end=str.length()-1;

    while(start<end){
        if(isalpha(str[start]) && isalpha(str[end])){
            char temp=str[start];
            str[start]=str[end];
            str[end]=temp;

            start++;
            end--;
        }
        else if(!isalpha(str[start])){
            start++;
        }
        else{
            end--;
        }
    }
    return str;
}

int main(){
    string str="a-bd-cfi!";

    cout<<reverseOnlyLetters(str);

    return 0;
}