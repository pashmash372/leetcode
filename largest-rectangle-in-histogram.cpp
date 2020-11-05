#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        s.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                int p = s.top();
                s.pop();
                maxarea = max(maxarea, heights[p] * (i - s.top() - 1));
            }
            s.push(i);
        }
        while (s.top() != -1)
        {
            int p = s.top();
            s.pop();
            int temp = heights[p] * (heights.size() - s.top() - 1);
            maxarea = max(maxarea, temp);
        }
        return maxarea;
    }
};
int main()
{
    Solution s;
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(v);
    return 0;
}