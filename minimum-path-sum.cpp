#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (i == 1)
                {
                    dp[i][j] = grid[i - 1][j - 1] + dp[i][j - 1];
                }
                else if (j == 1)
                {
                    dp[i][j] = grid[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        for (auto &i : dp)
        {
            for (auto &j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    vector<vector<int>> v = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    Solution s;
    cout << s.minPathSum(v);
}