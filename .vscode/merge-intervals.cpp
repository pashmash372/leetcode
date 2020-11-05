#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(
            intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
            });
        for (auto i : intervals)
        {
            if (ans.empty() || ans.back()[1] < i[0])
            {
                ans.push_back(i);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
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
    // vector<pair<int, int>> vect;
    vector<vector<int>> vect = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {5, 5}};
    int n = sizeof(vect) / sizeof(vect[0]);

    Solution s;
    s.merge(vect);

    return 0;
}