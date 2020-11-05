#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestDistance(vector<string> words, string word1, string word2)
    {
        int minDistance = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
            {
                for (int j = 0; j < words.size(); j++)
                {
                    if (words[j] == word2)
                    {
                        minDistance = min(minDistance, abs(i - j));
                    }
                }
            }
        }
        return minDistance;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding";
    string word2 = "practice";
    // string word1 = "makes";
    // string word2 = "coding";
    cout << s.shortestDistance(words, word1, word2);

    return 0;
}
