#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int T, B, L, R;
        T = 0, B = n - 1, L = 0, R = n - 1;
        int sqN = n * n;
        int i = 1;
        int dir = 0;
        vector<vector<int>> ans(n, vector<int>(n));
        while (i <= sqN)
        {
            if (dir == 0)
            {
                for (int k = L; k <= R; k++)
                {
                    ans[T][k] = i;
                    i++;
                }
                T++;
            }
            if (dir == 1)
            {
                for (int k = T; k <= B; k++)
                {
                    ans[k][R] = i;
                    i++;
                }
                R--;
            }
            if (dir == 2)
            {
                for (int k = R; k >= L; k--)
                {
                    ans[B][k] = i;
                    i++;
                }
                B--;
            }
            if (dir == 3)
            {
                for (int k = B; k >= T; k--)
                {
                    ans[k][L] = i;
                    i++;
                }
                L++;
            }
            dir = (dir + 1) % 4;
        }
        // for (auto i : ans)
        // {
        //     for (auto j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};

int main()
{
    Solution s;
    s.generateMatrix(5);
    return 0;
}