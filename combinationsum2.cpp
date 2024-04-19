#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    if (target < 0)
    {
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        temp.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> temp;
    vector<vector<int>> ans;
    solve(candidates, target, 0, temp, ans);
    return ans;
}

int main()
{
    vector<int> candidates = {1, 4, 8, 4};
    int target = 9;

    vector<vector<int>> ans = combinationSum2(candidates, target);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}