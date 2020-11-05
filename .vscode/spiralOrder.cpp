#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> ans;
        if (M == 0 || N == 0)
            return ans;
        int T, B, L, R;
        T = 0, B = M - 1, L = 0, R = N - 1;
        int dir = 0;

        while (L <= R && T <= B)
        {
            if (dir == 0)
            {
                for (int k = L; k <= R; k++)
                {
                    cout << matrix[T][k];
                    ans.push_back(matrix[T][k]);
                }

                T++;
            }
            else if (dir == 1)
            {
                for (int k = T; k <= B; k++)
                {
                    cout << matrix[k][R];
                    ans.push_back(matrix[k][R]);
                }

                R--;
            }
            else if (dir == 2)
            {
                for (int k = R; k >= L; k--)
                {
                    cout << matrix[B][k];
                    ans.push_back(matrix[B][k]);
                }
                B--;
            }
            else if (dir == 3)
            {
                for (int k = B; k >= T; k--)
                {
                    cout << matrix[k][L];
                    ans.push_back(matrix[k][L]);
                }

                L++;
            }
            dir = (dir + 1) % 4;
        }
    }
};

int main()
{
    Solution s;

    vector<vector<int>> v;
    v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    s.spiralOrder(v);

    return 0;
}