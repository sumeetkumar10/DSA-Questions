#include<iostream>
#include<vector>
using namespace std;

vector<int> findLeaders(int arr[],int n){
    vector<int> ans;
    int maxi=arr[n-1];
    ans.push_back(maxi);

    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(maxi);
            maxi=arr[i];
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