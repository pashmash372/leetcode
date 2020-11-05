#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][101];
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return uniquePathsUtil(m, n);
    }
    int uniquePathsUtil(int m, int n)
    {
        if (m == 1 || n == 1)
            return 1;
        else
        {
            if (dp[m][n] != -1)
            {
                return dp[m][n];
            }
            return dp[m][n] = uniquePathsUtil(m - 1, n) + uniquePathsUtil(m, n - 1);
        }
    }
};
int main()
{
    int m = 7, n = 3;
    Solution s;
    cout << s.uniquePaths(m, n);
    return 0;
}