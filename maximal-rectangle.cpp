#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if(m==0)return 0;
        int n = matrix[0].size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> height(n);

        fill(right.begin(), right.end(), n);
        int mx = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    height[j]++;
                }
                else
                {
                    height[j] = 0;
                }
            }
            int leftBound = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    left[j] = max(left[j], leftBound);
                }
                else
                {
                    left[j] = 0;
                    leftBound = j + 1;
                }
            }
            int rightBound = n;
            for (int j = n - 1; j >= 0; j--)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = min(right[j], rightBound);
                }
                else
                {
                    right[j] = n;
                    rightBound = j;
                }
            }
            for (int j = 0; j < n; j++)
            {
                mx = max(mx, (right[j] - left[j]) * height[j]);
            }
            for (auto i : height)
            {
                cout << i << " ";
            }
            cout << endl;
            for (auto i : left)
            {
                cout << i << " ";
            }
            cout << endl;
            for (auto i : right)
            {
                cout << i << " ";
            }
            cout << endl;
            cout << endl;
        }
        return mx;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    cout << s.maximalRectangle(matrix);

    return 0;
}