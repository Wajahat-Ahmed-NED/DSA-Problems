// Optimized Approach
// TC: O(N)+O(M)+O(NxM)*4 == O(NxM);
// SC: O(NxM)

class Solution
{

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delRow[], int delCol[])
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0 && board[nRow][nCol] == 'O')
            {
                vis[nRow][nCol] = 1;
                dfs(nRow, nCol, vis, board, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Traverse from boundary
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && board[0][j] == 'O')
            {
                vis[0][j] = 1;
                dfs(0, j, vis, board, delRow, delCol);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
            {
                vis[n - 1][j] = 1;
                dfs(n - 1, j, vis, board, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
            {
                vis[i][0] = 1;
                dfs(i, 0, vis, board, delRow, delCol);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            {
                vis[i][m - 1] = 1;
                dfs(i, m - 1, vis, board, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};