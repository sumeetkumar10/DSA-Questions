#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(int arr[],int n,int target){
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        int ele=arr[i];
        int more=target-ele;

        if(mp.find(more)!=mp.end()){
            return {mp[more],i};
        }
        mp[ele]=i;
    }
    return {-1,-1};
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target"<<endl;
    cin>>target;

    vector<int> ans=twoSum(arr,n,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}