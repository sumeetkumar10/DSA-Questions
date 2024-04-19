#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string removeAdjacentDuplicates(string str){
    string ans="";
    stack<char> st;

    int i=0;
    while(i<str.length()){
        if(!st.empty() && st.top()==str[i]){
            st.pop();
        }
        else{
            st.push(str[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string str="abbaca";

    cout<<"The String obtained after removing Adjacent duplicates is "<<removeAdjacentDuplicates(str)<<"."<<endl;

    return 0;
}