#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int n = digits.size();
        vector<int> result;
        for (int i = n - 1; i >= 0; i--)
        {
            int val = digits[i] + carry;
            result.push_back(val % 10);
            carry = val / 10;
        }
        if (carry == 1)
        {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main()
{
    Solution s;
    // vector<int> v = {1, 2, 9};
    vector<int> v = {9, 9, 9};
    // vector<int> v = {1, 2, 3};

    vector<int> ans = s.plusOne(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}