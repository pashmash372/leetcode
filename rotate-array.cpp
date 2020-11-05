#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> a(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            a[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = a[i];
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);
    return 0;
}