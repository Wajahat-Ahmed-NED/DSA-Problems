// TC: O(NxM) * 4
// SC: O(NxM)
class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty())
        {

            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol] == '1')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }
};