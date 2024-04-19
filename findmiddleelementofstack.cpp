#include<iostream>
#include<stack>
using namespace std;

void findMiddle(stack<int>& st,int size){
    if(st.empty()){
        return ;
    }

    if(st.size()==size/2+1){
        cout<<st.top();
        return ;
    }

    int top=st.top();
    st.pop();

    findMiddle(st,size);

    st.push(top);
}

int main(){
    stack<int> st;

    st.push(93);
    st.push(96);
    st.push(99);
    st.push(102);
    st.push(105);

    findMiddle(st,st.size());

    return 0;
}