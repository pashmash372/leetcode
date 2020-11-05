#include <bits/stdc++.h>
using namespace std;
class WordDistance
{
public:
    unordered_map<string, vector<int>> locs;
    WordDistance(vector<string> words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            if (locs.find(words[i]) == locs.end())
            {
                vector<int> dummy;
                locs[words[i]] = dummy;
            }
            locs.at(words[i]).push_back(i);
        }
    }
    int shortest(string word1, string word2)
    {
        vector<int> indices1 = locs.at(word1);
        vector<int> indices2 = locs.at(word2);
        int shortest = INT_MAX;
        for (int i = 0, j = 0; i < indices1.size() && j < indices2.size();)
        {
            int index1 = indices1.at(i);
            int index2 = indices2.at(j);
            if (index1 > index2)
            {
                shortest = min(shortest, index1 - index2);
                j++;
            }
            else
            {
                shortest = min(shortest, index2 - index1);
                i++;
            }
        }
        return shortest;
    }
};
int main()
{
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "coding";
    string word2 = "practice";
    // string word1 = "makes";
    // string word2 = "coding";
    WordDistance w(words);
    cout << w.shortest(word1, word2);

    return 0;
}