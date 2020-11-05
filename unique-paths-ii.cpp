#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int dp[101][101];

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 0 || n == 0 || obstacleGrid[0][0] == 1)
            return 0;
        // memset(dp, -1, sizeof(dp));

        return uniquePathsWithObstaclesUtil(obstacleGrid, m, n);
    }
    int uniquePathsWithObstaclesUtil(vector<vector<int>> &v, int m, int n)
    {
        int dp[m + 1][n + 1];
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (v[i - 1][j - 1] == 0)
                {
                    if (i == 1 && j == 1)
                    {
                        dp[i][j] = 1;
                    }
                    else if (i == 1)
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else if (j == 1)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
                else if (v[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    // vector<vector<int>> v = {
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 0}};
    vector<vector<int>> v = {
        {0, 0},
        {1, 1},
        {0, 0}};

    Solution s;
    cout << s.uniquePathsWithObstacles(v);
    return 0;
}