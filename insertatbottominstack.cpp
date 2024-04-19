#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& st,int ele){
    if(st.empty()){
        st.push(ele);
        return ;
    }

    int top=st.top();
    st.pop();

    solve(st,ele);

    st.push(top);
}

void insertAtBottom(stack<int>& st){
    if(st.empty()){
        return ;
    }

    int top=st.top();
    st.pop();

    solve(st,top);
}

void printStack(stack<int>& st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> st;

    st.push(3);
    st.push(36);
    st.push(27);
    st.push(24);
    st.push(9);

    insertAtBottom(st);
    printStack(st);

    return 0;
}