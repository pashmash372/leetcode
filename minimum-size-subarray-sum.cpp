#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};
int main()
{
    Solution s;
    int sum = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(sum, nums);
    return 0;
}