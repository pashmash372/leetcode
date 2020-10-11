#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;

        int maxArea = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                maxArea = max(maxArea, height[i] * (j - i));
                i++;
            }
            else
            {
                maxArea = max(maxArea, height[j] * (j - i));
                j--;
            }
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int N = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + N);
    cout
        << s.maxArea(v);
    return 0;
}
