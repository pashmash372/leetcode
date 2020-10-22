#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, k = 0, j = 0;
        int n = nums.size();
        while (i < n)
        {
            j = i;
            while (j < n && nums[i] == nums[j])
            {
                j++;
            }
            if (j - i >= 2)
            {
                nums[k++] = nums[i++];
                nums[k++] = nums[i++];
            }
            else
            {
                nums[k++] = nums[i++];
            }
            i = j;
        }
        return k;
    }
};
int main()
{
    Solution s;
    vector<int> v = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << s.removeDuplicates(v);
    return 0;
}