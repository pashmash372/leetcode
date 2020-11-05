#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int threeSumSmaller(vector<int> nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            sum += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return sum;
    }
    int twoSumSmaller(vector<int> nums, int startIndex, int target)
    {
        int sum = 0;
        for (int i = startIndex; i < nums.size() - 1; i++)
        {
            int j = binarySearch(nums, i, target - nums[i]);
            sum += j - i;
        }
        return sum;
    }
    int binarySearch(vector<int> nums, int startIndex, int target)
    {
        int left = startIndex;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;
    cout << s.threeSumSmaller(nums, target);

    return 0;
}