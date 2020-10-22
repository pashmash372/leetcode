#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = 0;
        int k = nums.size() - 1;

        while (j <= k)
        {
            if (nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                j++;
            else if (nums[j] == 2)
                swap(nums[j], nums[k--]);
        }
        for (auto i : nums)
        {
            cout << i << " ";
        }
    }
};
int main()
{
    Solution s;
    // vector<int> v = {2, 0, 2, 1, 1, 0};
    vector<int> v = {1, 2, 0};
    s.sortColors(v);
    return 0;
}