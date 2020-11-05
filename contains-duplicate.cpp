#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (auto i : nums)
        {
            if (s.find(i) != s.end())
            {
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsDuplicate(nums);
    return 0;
}