#include<iostream>
using namespace std;

string removeOccurrences(string str,string part){
    int pos=str.find(part);
    while(pos!=string::npos){
        str.erase(pos,part.length());
        pos=str.find(part);
    }
    return str;
}

int main(){
    string str="daabcbaabcbc";
    string part="abc";

    cout<<"The String obtained after remove all the occurrences of "<<part<<" is "<<removeOccurrences(str,part)<<"."<<endl;

    return 0;
}