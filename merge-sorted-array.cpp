#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)

    {
        for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0 && j >= 0; k--)
        {
            nums1[k] = (i < 0 || nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
        }
    }
};
int main()
{
    Solution s;
    vector<int> a = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> b = {2, 5, 6};
    int n = 3;
    s.merge(a, m, b, n);
    return 0;
}