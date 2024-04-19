#include<iostream>
#include<climits>
using namespace std;

int stringToInteger(string str){
    int n=str.length();
    int i=0;
    int ans=0;

    while(str[i]==' '){
        i++;
    }
    
    bool condition=true;
    if(str[i]=='+' || str[i]=='-'){
        condition=str[i]=='+'?true:false;
        i++;
    }

    while(i<n && isdigit(str[i])){
        ans=ans*10+str[i++]-'0';

        if(ans>INT_MAX){
            return !condition?INT_MIN:INT_MAX;
        }
    }
    return condition?ans:-ans;
}

int main(){
    string str="      96";

    cout<<stringToInteger(str)<<endl;

    return 0;
}