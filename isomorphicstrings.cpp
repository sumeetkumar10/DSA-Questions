#include<iostream>
using namespace std;

bool isIsomorphic(string s,string t){
    int hash[256]={0};
    bool isCharsMapped[256]={0};

    for(int i=0;i<s.length();i++){
        while(hash[s[i]]==0 && isCharsMapped[t[i]]==0){
            hash[s[i]]=t[i];
            isCharsMapped[t[i]]=true;
            break;
        }
    }

    for(int i=0;i<s.length();i++){
        if(hash[s[i]]!=t[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s="abb";
    string t="cdd";

    if(isIsomorphic(s,t)){
        cout<<s<<" and "<<t<<" Are Isomorphic Strings."<<endl;
    }
    else{
        cout<<s<<" and "<<t<<" Are not Isomorphic Strings."<<endl;
    }

    return 0;
}