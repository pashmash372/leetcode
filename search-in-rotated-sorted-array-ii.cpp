#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;
        int l = 0;
        int h = nums.size() - 1;
        while (l <= h)
        {
            int m;
            m = l + (h - l) / 2;
            if (nums[m] == target)
                return true;
            if (nums[l] == nums[m] && nums[h] == nums[m])
            {
                l++;
                h--;
            }
            else if (nums[l] == nums[m])
            {
                l = m + 1;
            }
            else if (nums[m] == nums[h])
            {
                h = m - 1;
            }
            else if (nums[l] < nums[m])
            {
                if (nums[l] <= target && target < nums[m])
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else if (nums[l] > nums[m])
            {
                if (nums[m] < target && target <= nums[h])
                {
                    l = m + 1;
                }
                else
                {
                    h = m - 1;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 2;
    cout << s.search(nums, target);
    return 0;
}