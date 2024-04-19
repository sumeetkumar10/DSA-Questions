#include<iostream>
#include<vector>
using namespace std;

vector<int> findLeaders(int arr[],int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader=false;
                break;
            }
        }
        if(leader){
            ans.push_back(arr[i]);
        }
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

    vector<int> ans=findLeaders(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}