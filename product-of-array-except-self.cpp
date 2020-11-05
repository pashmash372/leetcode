#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        int res[n];
        res[0] = 1;
        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= right;
            right *= nums[i];
        }

        vector<int> ans(res, res + n);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = s.productExceptSelf(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}