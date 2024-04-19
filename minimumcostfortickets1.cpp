#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &days, vector<int> &costs, int index)
{
    vector<int> dp(days.size() + 1, INT_MAX);
    int n = days.size();
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int op1 = costs[0] + dp[k + 1];

        int i;
        // 7 days pass
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int op2 = costs[1] + dp[i];

        // 30 days pass
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int op3 = costs[2] + dp[i];

        dp[k] = min(op1, min(op2, op3));
    }
    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return solve(days, costs, 0);
}

int main()
{
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};

    vector<int> costs = {2, 7, 15};

    cout << "The minimum cost for tickets is " << mincostTickets(days, costs) << endl;

    return 0;
}