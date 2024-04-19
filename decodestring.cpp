#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string decodeString(string str){
    string ans="";
    stack<string> st;

    for(auto ch:str){
        if(ch==']'){
            string repeatString="";
            while(!st.empty() && st.top()!="["){
                repeatString+=st.top();
                st.pop();
            }

            st.pop();
            string numericTimes="";
            while(!st.empty() && isdigit(st.top()[0])){
                numericTimes=st.top();
                st.pop();
            }
            reverse(numericTimes.begin(),numericTimes.end());
            int n=stoi(numericTimes);

            string decode="";
            while(n--){
                decode+=repeatString;
            }
            st.push(decode);
        }
        else{
            string temp(1,ch);
            st.push(temp);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string str="3[a2[b]]";

    cout<<"The Decode String is "<<decodeString(str)<<endl;

    return 0;
}