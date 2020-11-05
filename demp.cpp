#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int n = s.length();
        int ans = 0;
        for (int i = 0, j = 0; j < n; j++)
        {

            char key=s[j];
            if (mp.find(key) != mp.end())
            {
                i = max(i, mp[s[j]]);
            }
            ans = max(ans, j - i + 1);
            mp[s[j]] = j + 1;
        }
        return ans;
    }
};

int main()
{

    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb");
    return 0;
}