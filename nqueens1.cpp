#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int n, int row, int col)
{
    int i = row;
    int j = col;

    while (j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        j--;
    }

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

vector<vector<int>> solve(vector<vector<int>> &board, int n, int col, vector<int> &temp, vector<vector<int>> &ans)
{
    if (col >= n)
    {
        ans.push_back(temp);
        return ans;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, n, row, col))
        {
            temp.push_back(row + 1);
            board[row][col] = 1;
            solve(board, n, col + 1, temp, ans);

            temp.pop_back();
            board[row][col] = 0;
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n = 9;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> res = solve(board, n, 0, temp, ans);
    int N = res.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;

    return 0;
}