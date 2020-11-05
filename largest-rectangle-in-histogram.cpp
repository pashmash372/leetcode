#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        if (heights.size() == 0)
            return 0;
        if (heights.size() == 1)
            return heights[0];

        vector<int> rightV;
        vector<int> leftV;
        stack<vector<int>> s;
        int size = heights.size();
        nsrwithpair(heights, size, rightV, s);
        while (!s.empty())
        {
            s.pop();
        }
        nslwithpair(heights, size, leftV, s);

        int width = 0;
        int area = 0;
        for (int i = 0; i < rightV.size(); i++)
        {
            width = rightV[i] - leftV[i] - 1;
            area = max(area, heights[i] * width);
        }
        return area;
    }
    void nsrwithpair(vector<int> heights, int size, vector<int> &rightV, stack<vector<int>> &s)
    {
        vector<int> v;
        for (int i = size - 1; i >= 0; i--)
        {
            if (s.size() == 0)
            {
                rightV.push_back(7);
            }
            else if (s.size() > 0 && s.top()[0] < heights[i])
            {
                rightV.push_back(s.top()[1]);
            }
            else if (s.size() > 0 && s.top()[0] >= heights[i])
            {
                while (s.size() > 0 && s.top()[0] >= heights[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    rightV.push_back(7);
                }
                else
                {
                    rightV.push_back(s.top()[1]);
                }
            }

            // s.push(make_pair(heights[i], i));
            v = {heights[i], i};
            s.push(v);
        }
        reverse(rightV.begin(), rightV.end());
    }
    void nslwithpair(vector<int> heights, int size, vector<int> &leftV, stack<vector<int>> &s)
    {
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            if (s.size() == 0)
            {
                leftV.push_back(-1);
            }
            else if (s.size() > 0 && s.top()[0] < heights[i])
            {
                leftV.push_back(s.top()[1]);
            }
            else if (s.size() > 0 && s.top()[0] >= heights[i])
            {
                while (s.size() > 0 && s.top()[0] >= heights[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    leftV.push_back(-1);
                }
                else
                {
                    leftV.push_back(s.top()[1]);
                }
            }

            // s.push(make_pair(heights[i], i));
            v = {heights[i], i};
            s.push(v);
        }
    }
};

int main()
{
    Solution s;
    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    // vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    vector<int> heights = {3};
    cout << s.largestRectangleArea(heights);
    return 0;
}
