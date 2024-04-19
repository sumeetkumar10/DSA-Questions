#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& st,int ele){
    if(st.empty()){
        st.push(ele);
        return ;
    }

    int top=st.top();
    st.pop();

    insertAtBottom(st,ele);
    st.push(top);
}

void reverseStack(stack<int>& st){
    if(st.empty()){
        return ;
    }

    int top=st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st,top);
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
    st.push(9);
    st.push(18);
    st.push(27);
    st.push(15);

    reverseStack(st);
    printStack(st);

    return 0;
}