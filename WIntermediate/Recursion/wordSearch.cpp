class Solution
{
public:
    bool dfs(int row, int col, int ind, vector<vector<char>> &board, string &word, vector<vector<int>> &visited)
    {
        if (ind == word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[ind] || visited[row][col])
        {
            return false;
        }

        visited[row][col] = true;

        int delRow[4] = {-1, 1, 0, 0};
        int delCol[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (dfs(nRow, nCol, ind + 1, board, word, visited))
            {
                return true;
            }
        }

        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(i, j, 0, board, word, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
