#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(int arr[],int n,int target){
    vector<int> ans;
    int left=0,right=n-1;
    int sum=arr[0];

    while(left<right){
        int sum=arr[left]+arr[right];

        if(sum>target){
            right--;
        }
        else if(sum<target){
            left++;
        }
        else{
            ans.push_back(left+1);
            ans.push_back(right+1);
            return ans;
        }
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