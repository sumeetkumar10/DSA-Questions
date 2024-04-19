#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool isUnique(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return false;
        }
    }
    return true;
}

vector<int> findThreeMaxUniqueElements(int arr[], int n) {
    int firstMax = arr[0], secondMax = INT_MIN, thirdMax = INT_MIN;
    int count = 0;

    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (arr[i] > firstMax) {
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax) {
            thirdMax = secondMax;
            secondMax = arr[i];
        } else if (arr[i] > thirdMax) {
            thirdMax = arr[i];
        }
    }

    if (isUnique(arr, n, firstMax)) {
        ans.push_back(firstMax);
        count++;
    }
    if (isUnique(arr, n, secondMax)) {
        ans.push_back(secondMax);
        count++;
    }
    if (isUnique(arr, n, thirdMax)) {
        ans.push_back(thirdMax);
        count++;
    }
    return ans;
}

int main(){
    int arr[]={10,10,9,9,7};

    vector<int> res=findThreeMaxUniqueElements(arr,5);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}