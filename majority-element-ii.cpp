#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> res;
        if (nums.empty())
            return res;
        int num1 = 0, count1 = 0, num2 = 0, count2 = 0;
        for (auto n : nums)
        {
            if (n == num1)
                count1++;
            else if (n == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = n;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = n;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (auto n : nums)
        {
            if (n == num1)
            {
                count1++;
            }
            else if (n == num2)
            {
                count2++;
            }
        }
        if (count1 > nums.size() / 3)
        {
            res.push_back(num1);
        }
        if (count2 > nums.size() / 3)
        {
            res.push_back(num2);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 2, 3};
    s.majorityElement(nums);
    return 0;
}