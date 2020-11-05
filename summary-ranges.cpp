#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> summary;
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            if (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1)
                continue;
            if (i == j)
                summary.push_back(to_string(nums[i]));
            else
            {
                summary.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j + 1;
        }
        return summary;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> ans = s.summaryRanges(nums);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}