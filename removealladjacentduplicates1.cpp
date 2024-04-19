#include<iostream>
using namespace std;

string removeAdjacentDuplicates(string str){
    string temp="";

    int i=0;
    while(i<str.length()){
        if(temp.length()>0){
            if(temp[temp.length()-1]==str[i]){
                temp.pop_back();
            }
            else{
                temp.push_back(str[i]);
            }
        }
        else{
            temp.push_back(str[i]);
        }
        i++;
    }
    return temp;
}

int main(){
    string str="abbaca";

    cout<<"The String obtained after removing Adjacent duplicates is "<<removeAdjacentDuplicates(str)<<"."<<endl;

    return 0;
}