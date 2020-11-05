#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> ip = nums;
        vector<int> op;
        vector<vector<int>> ans;
        solve(ip, op, ans);
        return ans;
    }
    void solve(vector<int> ip, vector<int> op, vector<vector<int>> &ans)
    {
        if (ip.empty())
        {
            ans.push_back(op);
            return;
        }
        vector<int> op1;
        vector<int> op2;
        op1 = op;
        op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin(), ip.begin() + 1);
        solve(ip, op1, ans);
        solve(ip, op2, ans);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = s.subsets(nums);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}