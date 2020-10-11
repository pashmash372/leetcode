#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        int N = nums.size();
        if (N == 3)
        {
            int sum = 0;
            for (auto i : nums)
            {
                sum += i;
            }
            return sum;
        }

        int a, b, c;
        int minDiff = INT_MAX;
        int ans = 0;
        int sum3 = 0;
        for (int i = 0; i < N - 2; i++)
        {
            a = nums[i];
            // if (a >= target)
            //     continue;
            int start = i + 1, end = N - 1;
            while (start < end)
            {
                b = nums[start];
                c = nums[end];
                sum3 = a + b + c;
                if (sum3 == target)
                {
                    return target;
                }
                else if (sum3 < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
                // minDiff = min(minDiff, abs(target - (a + b + c)));

                if (minDiff > abs(target - sum3))

                {
                    minDiff = abs(target - sum3);
                    ans = sum3;
                }
            }
        }
        return ans;
    }
};

int main()
{
    // int target = 1;
    // vector<int> v = {-1, 2, 1, -4};
    int target = 0;
    vector<int> v = {1, 1, 1, 1};
    Solution s;
    cout << s.threeSumClosest(v, target);
    return 0;
}