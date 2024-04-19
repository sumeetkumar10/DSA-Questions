#include <iostream>
#include<vector>
#include<math.h>

using namespace std;

 int find(int n)
{
    if(n<=1)
    return n;
        
    return find(n-1)+find(n-2);
}
// -------------------------------------------------
int fib(int n, vector<int>& dp)
{
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= (fib(n-1,dp) + fib(n-2,dp))%1000000007;
}

int nthFibonacci(int n)
{
   vector<int> dp(n+1,-1);
   return fib(n,dp);
}
// -------------------------------------------------
int fib(int n,vector<int>&dp){
   dp[0]=0;
   dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
    }
    return dp[n];
   
}

int nthFibonacci(int n)
{
    vector<int> dp(n+1,-1);
    return fib(n,dp);
}
// -------------------------------------------------
int fib(int n)
{
    int prevToPrev=0;
    int prev=1;
    for(int i=2;i<=n;i++)
    {
        int curr=(prevToPrev+prev)%1000000007;
        prevToPrev=prev;
        prev=curr;
    }
    return prev;
   
}
// -------------------------------------------------
int fib(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0];
}

void power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
 
    power(F, n / 2);
    multiply(F, F);
 
    if (n % 2 != 0)
        multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];
 
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
// -------------------------------------------------------------------------
int fibonacciUsingGoldenRatio(int n) 
{
    double goldenRatio = (1 + sqrt(5)) / 2;
    return round(pow(goldenRatio, n) / sqrt(5));
}

int main()
{
    int n = 9;
    //
    cout<<fib(n);

    return 0;
}