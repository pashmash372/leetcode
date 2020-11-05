#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(ans, comb, k, 1, n);
        return ans;
    }
    void backtrack(vector<vector<int>> &ans, vector<int> &comb, int k, int start, int n)
    {
        if (comb.size() > k)
            return;
        if (comb.size() == k && n == 0)
        {
            vector<int> res = comb;
            ans.push_back(res);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            if (n - i >= 0)
            {
                comb.push_back(i);
                backtrack(ans, comb, k, i + 1, n - i);
                comb.erase(comb.begin() + comb.size() - 1);
            }
        }
    }
};
int main()
{
    Solution s;
    int k = 3, n = 7;
    vector<vector<int>> ans = s.combinationSum3(k, n);
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