#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isCol = false;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                isCol = true;
            }
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (isCol)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        // for (auto i : matrix)
        // {
        //     for (auto j : i)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> v = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(v);

    return 0;
}