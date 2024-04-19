#include<iostream>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;

int longestConsecutiveSequence(int arr[],int n){
    if(n==0){
        return 0;
    }
    int longest=1;

    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int count=1;
            int x=it;

            while(st.find(x+1)!=st.end()){
                x++;
                count++;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}

int main(){
    int n;
    cout<<"Enter the size of the array you want to create"<<endl;
    cin>>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The longest consecutive sequence in the array is of "<<longestConsecutiveSequence(arr,n)<<" length."<<endl;

    return 0;
}