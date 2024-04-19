#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NSL(int arr[],int n){
    vector<int> ans;
    stack<int> st;

    for(int i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(-1);
        }
        else if(st.size()>0 && st.top()<arr[i]){
            ans.push_back(st.top());
        }
        else if(st.size()>0 && st.top()>=arr[i]){
            while(st.size()>0 && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> ans=NSL(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}