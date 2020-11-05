#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
            return ans;
        vector<vector<int>> subsets;
        sort(nums.begin(), nums.end());
        vector<int> se;
        backtrack(subsets, nums, 0, se);
        return subsets;
    }
    void backtrack(vector<vector<int>> &subsets, vector<int> &nums, int pos, vector<int> &se)
    {
        subsets.push_back(se);
        for (int i = pos; i < nums.size(); i++)
        {
            if (i != pos && nums[i] == nums[i - 1])
            {
                continue;
            }
            se.push_back(nums[i]);
            backtrack(subsets, nums, i + 1, se);
            se.erase(se.end());
        }
    }
};

int main()
{
    Solution s;
    vector<int> v = {4, 4, 4, 1, 4};
    vector<vector<int>> ans = s.subsetsWithDup(v);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
