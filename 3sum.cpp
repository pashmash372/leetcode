#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int N = sizeof(nums) / sizeof(nums[0]);
        int start, end;
        int a, b, c;
        typedef vector<int> pii;
        vector<int> v;
        vector<pii> ans;

        for (int i = 0; i < N; i++)
        {
            start = i + 1;
            end = N - 1;
            a = nums[i];

            while (start < end && start >= 0 && end < N && start != i && end != i)
            {
                b = nums[start];
                c = nums[end];
                if (a = (b + c))
                {
                    v.push_back(a);
                    v.push_back(b);
                    v.push_back(c);
                    ans.push_back(v);
                    start++;
                    end--;
                    continue;
                }
                if (a > b + c)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        // return ans;
    }
};

int main()
{
    Solution s;
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int N = sizeof(nums) / sizeof(nums[0]);
    vector<int> v(nums, nums + N);
    s.threeSum(v);
    return 0;
}