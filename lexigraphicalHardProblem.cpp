#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int lexigraphicalHardProblem(int n, int k, int arr[])
{
    map<int, int> mp;
    bool flag;
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    while (true)
    {
        flag = false;
        for (auto i : mp)
        {
            if (i.second >= k && i.first > 1)
            {
                mp[i.first]--;
                mp[i.first - 1]++;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
    for (auto i : mp)
    {
        mx = max(mx, i.second);
    }
    int ans;
    for (auto i : mp)
    {
        if (i.second == mx)
        {
            ans = i.first;
            break;
        }
    }
    return ans;
}

int main()
{
    // int n = 5;
    // int k = 2;
    // int arr[] = {1, 3, 2, 2, 2};
    // int n = 4;
    // int k = 2;
    // int arr[] = {100, 100, 100, 100};
    int n = 10;
    int k = 4;
    int arr[] = {3, 4, 1, 3, 3, 4, 4, 4, 4, 3};
    int result = lexigraphicalHardProblem(n, k, arr);
    cout << result;
    return 0;
}