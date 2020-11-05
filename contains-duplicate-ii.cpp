#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            if (s.size() > k)
            {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    // vector<int> nums = {1, 2, 3, 1};
    // int k = 3;
    vector<int> nums{1, 2, 3, 1, 2, 3};
    int k = 2;
    cout << s.containsNearbyDuplicate(nums, k);
    return 0;
}