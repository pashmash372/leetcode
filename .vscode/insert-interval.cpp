#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
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

        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        return ans;
    }
};
int main()
{
    // vector<pair<int, int>> vect;
    vector<vector<int>> vect = {{1, 3},
                                {6, 9}};
    vector<int> newi = {2, 5};
    Solution s;
    s.insert(vect, newi);

    return 0;
}