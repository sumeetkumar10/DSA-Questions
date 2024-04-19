#include <iostream>
using namespace std;

long long int power(int x, int n)
{
    // if(n==0){
    //     return 1;
    // }

    // if(n==1){
    //     return x;
    // }

    // long long int ans=power(x,n/2);
    // if(n%2==0){
    //     return ans*ans;
    // }
    // else{
    //     return x*ans*ans;
    // }

    long long int i = 0;
    long long int ans = x;
    while (i <= n)
    {
        ans = ans * n;
        i++;
    }
    return ans;
}

int main()
{
    int x = 3;
    int n = 3;

    cout << x << "^" << n << " = " << power(x, n) << endl;

    return 0;
}