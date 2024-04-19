#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
{
    int n = days.size();

    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    // 1 day pass
    int op1 = costs[0] + solve(days, costs, index + 1, dp);

    int i;
    // 7 days pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int op2 = costs[1] + solve(days, costs, i, dp);

    // 30 days pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int op3 = costs[2] + solve(days, costs, i, dp);

    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    vector<int> dp(days.size() + 1, -1);
    return solve(days, costs, 0,dp);
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};

    vector<int> costs = {2, 7, 15};

    cout << "The minimum cost for tickets is " << mincostTickets(days, costs) << endl;

    return 0;
}