#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findMissingRanges(vector<int> nums, int lower, int upper)
    {
        vector<string> res;
        if (nums.empty())
        {
            res.push_back(rangeString(lower, upper));
            return res;
        }
        int nextMissing = lower;
        for (int num : nums)
        {
            if (nextMissing == num - 1)
            {
                res.push_back(rangeString(nextMissing, nextMissing));
            }
            else if (nextMissing < num)
            {
                res.push_back(rangeString(nextMissing, num - 1));
            }
            if (num == INT_MAX)
                return res;
            nextMissing = num + 1;
        }
        if (nextMissing == upper)
        {
            res.push_back(rangeString(nextMissing, nextMissing));
        }
        else if (nextMissing < upper)
        {
            res.push_back(rangeString(nextMissing, upper));
        }
        return res;
    }
    string rangeString(int lower, int upper)
    {
        if (lower == upper)
        {
            return to_string(lower);
        }
        else
        {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;
    vector<string> ans = s.findMissingRanges(nums, lower, upper);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}