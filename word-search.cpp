#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string &word, int index, int x, int y)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index])
        {
            return false;
        }
        if (index == word.size() - 1)
        {
            return true;
        }
        bool found = false;
        char temp = board[x][y];
        board[x][y] = ' ';

        found = dfs(board, word, index + 1, x, y + 1) ||
                dfs(board, word, index + 1, x, y - 1) ||
                dfs(board, word, index + 1, x + 1, y) ||
                dfs(board, word, index + 1, x - 1, y);
        board[x][y] = temp;
        return found;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    cout << s.exist(board, word);
    return 0;
}