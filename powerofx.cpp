#include<iostream>
using namespace std;

double power(int x,int n){
    if(n==0){
        return 1;
    }

    if(n==1){
        return x;
    }

    double ans=power(x,n/2);
    if(n%2==0){
        return ans*ans;
    }
    else{
        return x*ans*ans;
    }
}

int main(){
    int x=9;
    int n=-3;

    double ans=power(x,n);
    if(n<0){
        ans=1/ans;
    }
    cout<<x<<"^"<<n<<" = "<<ans<<endl;

    return 0;
}