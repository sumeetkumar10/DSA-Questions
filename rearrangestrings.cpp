#include<iostream>
#include<climits>
using namespace std;

string rearrangeString(string str){
    int n=str.length();
    int hash[26]={0};

    for(int i=0;i<n;i++){
        hash[str[i]-'a']++;
    }

    int maxFreq=INT_MIN;
    char maxFreqChar;
    for(int i=0;i<26;i++){
        if(hash[i]>maxFreq){
            maxFreq=hash[i];
            maxFreqChar=i+'a';
        }
    }

    int index=0;
    while(maxFreq>0 && index<n){
        str[index]=maxFreqChar;
        maxFreq--;
        index+=2;
    }

    if(maxFreq!=0){
        return "";
    }

    for(int i=0;i<26;i++){
        while(hash[i]>0){
            index=index>=n?1:index;
            str[index]=i+'a';
            index+=2;
            hash[i]--;
        }
    }
    return str;
}

int main(){
    string str="aabgfaa";

    cout<<"The Rearranged String is "<<rearrangeString(str)<<"."<<endl;

    return 0;
}