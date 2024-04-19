#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> numberOfStacks(int arr[],int n){
    vector<int> ans;
    stack<pair<int,int>> st;

    for(int i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(-1);
        }
        else if(st.size()>0 && st.top().first>arr[i]){
            ans.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first<=arr[i]){
            while(st.size()>0 && st.top().first<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push(make_pair(arr[i],i));
    }
    for(int i=0;i<n;i++){
        ans[i]=i-ans[i];
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

    vector<int> ans=numberOfStacks(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}