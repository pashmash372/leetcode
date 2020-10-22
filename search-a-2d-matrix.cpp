#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i >= 0 && i < m && j >= 0 && j < n)
        {

            if (matrix[i][j] == target)
            {
                break;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
        }
        if (i >= 0 && j >= 0 && i < m && j < n)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    vector<vector<int>> v;
    int target = 27;
    cout << s.searchMatrix(v, target);
    return 0;
}