#include<iostream>
#include<vector>
using namespace std;

bool isAnagram(string s,string t){
    if(s.size()!=t.size()) return false;

    vector<int> freq(26,0);

    for(int i=0;i<26;i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }

    for(int i=0;i<freq.size();i++){
        if(freq[i]!=0) return false;
    }
    return true;
}

int main(){
    string s="anagram";
    string t="nagaram";



    return 0;
}