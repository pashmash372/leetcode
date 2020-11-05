#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> maxL, maxR;
        int mxl = INT_MIN, mxr = INT_MIN;
        for (int i = 0; i < height.size(); i++)
        {
            mxl = max(mxl, height[i]);
            maxL.push_back(mxl);
        }
        for (int i = height.size() - 1; i >= 0; i--)
        {
            mxr = max(mxr, height[i]);
            maxR.push_back(mxr);
        }
        reverse(maxR.begin(), maxR.end());
        vector<int> water;
        for (int i = 0; i < height.size(); i++)
        {
            water.push_back(min(maxL[i], maxR[i]) - height[i]);
        }
        int sum = 0;
        for (int i : water)
        {
            sum += i;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(v) << endl;
    return 0;
}