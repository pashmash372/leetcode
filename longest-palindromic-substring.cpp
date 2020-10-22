#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int static t[1001][1001];
    string longestPalindrome(string s)
    {
        memset(t, -1, sizeof(t));
        string rs = s;
        reverse(rs.begin(), rs.end());
        int m = s.length();
        int n = rs.length();
        cout << lcs(s, rs, m, n);
        return s;
    }
    int lcs(string s, string rs, int m, int n)

    {
        Solution sol;
        if (m == 0 || n == 0)
            return 0;
        if (*(t+m*n)!= -1)//t*m+n
        {
            return *(t+m*n);
        }
        if (s[m - 1] == rs[n - 1])
        {
            return *(t+m*n) = lcs(s, rs, m - 1, n - 1) + 1;
        }
        else
        {
            return *(t+m*n) = max(lcs(s, rs, m - 1, n),
                                 lcs(s, rs, m, n - 1));
        }
    }
};
int main()
{
    Solution s;
    string sr = "GEEKS FOR GEEKS";
    cout << s.longestPalindrome(sr);
    return 0;
}