#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];
class Solution
{
public:
    int lcs(string s, string rs, int m, int n)

    {

        if (m == 0 || n == 0)
            return 0;
        if (t[m][n] != -1)
        {
            return t[m][n];
        }
        if (s[m - 1] == rs[n - 1])
        {
            return t[m][n] = lcs(s, rs, m - 1, n - 1) + 1;
        }
        else
        {
            return t[m][n] = max(lcs(s, rs, m - 1, n),
                                 lcs(s, rs, m, n - 1));
        }
    }
};
int main()
{
    Solution s;
    string sr = "GEEKS FOR GEEKS";
    string tsr = sr;
    reverse(tsr.begin(), tsr.end());
    int m = sr.length();
    int n = tsr.length();
    memset(t, -1, sizeof(t));
            cout
        << s.lcs(sr, tsr, m, n);
    return 0;
}