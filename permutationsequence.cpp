#include<iostream>
#include<vector>
using namespace std;

string kthPermutation(int n,int k){
    string ans="";
    vector<int> numbers;

    int fact=1;
    for(int i=1;i<n;i++){
        fact*=i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    k--;
    while(true){
        ans+=to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/numbers.size();
    }
    return ans;
}

int main(){
    int n=4;

    int k=12;

    cout<<k<<"th Permutation In the Sequence is "<<kthPermutation(n,k)<<endl;

    return 0;
}