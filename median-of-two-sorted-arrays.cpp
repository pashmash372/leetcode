#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int partitionX, partitionY;
        int medianXY = (m + n + 1) / 2;
        // find partitionX
        int start = 0, end = m - 1, mid;
        int maxLeftX, minRightX, maxLeftY, minRightY;
        bool oddFlag = false;
        double ans = 0.0;
        if (m + n & 1)
            oddFlag = true;

        while (start <= end)
        {
            // mid = (start + end) / 2;
            mid = start + ((end - start) / 2);
            partitionX = mid;
            partitionY = medianXY - partitionX;

            maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX)
            {
                // found
                if (oddFlag)
                {
                    ans = (double)max(maxLeftX, maxLeftY);
                }
                else
                {
                    ans = (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }
                break;
            }
            else if (maxLeftY > minRightY)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return (double)ans;
    }
};

int main()
{

    Solution sol;
    // vector<int> nums1 = {1, 3, 8, 9, 15};
    // vector<int> nums2 = {7, 11, 18, 21, 25};
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2);
    return 0;
}