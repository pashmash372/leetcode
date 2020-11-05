#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        if (prices.empty() || prices.size() < 2)
            return maxProfit;
        int len = prices.size();
        vector<int> maxBy(len);
        vector<int> maxSince(len);
        fill(maxBy.begin(), maxBy.end(), 0);
        fill(maxSince.begin(), maxSince.end(), 0);
        int valley = prices[0];
        int peak = prices[len - 1];
        for (int i = 1; i < len; i++)
        {
            valley = min(valley, prices[i]);
            maxBy[i] = max(maxBy[i - 1], prices[i] - valley);
        }
        for (int i = len - 2; i >= 0; i--)
        {
            peak = max(peak, prices[i]);
            maxSince[i] = max(maxSince[i + 1], peak - prices[i]);
            maxProfit = max(maxProfit, maxBy[i] + maxSince[i]);
        }
        return maxProfit;
    }
};
int main()
{
    Solution s;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(v);
    return 0;
}