#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> distances;

        bfs(beginWord, endWord, dict, graph, distances);
        vector<vector<string>> paths;
        vector<int> v;
        dfs(beginWord, endWord, graph, distances, v, paths);
    }
    void bfs(string beginWord, string endWord, set<string> dict, unordered_map<string, vector<string>> graph, unordered_map<string, int> distances)
    {
        list<string> q;
        q.push_back(beginWord);
        distances[beginWord] = 0;
        while (q.empty())
        {
            string cur = q.front();
            q.pop_front();
        }
    }
};
int main()
{
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    s.findLadders(beginWord, endWord, wordList);
    return 0;
}