#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> num_set(nums.begin(), nums.end());
        int longestStreak = 0;
        for (auto num : num_set)
        {
            // num_set does not contain the key
            if (num_set.find(num - 1) == num_set.end())
            {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.find(currentNum + 1) != num_set.end())
                {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(nums);
    return 0;
}