#include<iostream>
#include<stack>
using namespace std;

// void reverseString(string& str,int start,int end){
//     while(start<end){
//         swap(str[start],str[end]);
//         start++;
//         end--;
//     }
// }




void reverseString(string& str){
    stack<int> st;
    int i=0;
    while(str[i]!='\0'){
        st.push(str[i]);
        i++;
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

void printString(string str){
    for(int i=0;i<str.length();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string str="SUMEET";

    cout<<str<<endl;
    // reverseString(str,0,str.length()-1);
    reverseString(str);
    cout<<str<<endl;

    return 0;
}