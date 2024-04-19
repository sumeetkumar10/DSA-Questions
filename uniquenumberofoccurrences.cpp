#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool uniqueOccurrences(int arr[],int n){
    vector<int> ans;
    int count=1;
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i-1]) count++;
        else{
            ans.push_back(count);
            count=1;
        }

        if(i==n-2 && arr[n-1]!=arr[n-2]) ans.push_back(1);
    }

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]==ans[i+1]) return false;
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    if(uniqueOccurrences(arr,n))
        cout<<"The array has unique Number of Occurrences."<<endl;
    else
        cout<<"The array does not have unique Number of Occurrences."<<endl;

    return 0;
}