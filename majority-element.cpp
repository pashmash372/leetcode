#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = NULL;
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution s;
    cout << s.majorityElement(nums);
    return 0;
}