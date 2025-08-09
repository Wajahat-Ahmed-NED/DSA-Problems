class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        // vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> minDist(n, vector<int>(m, -1));
        using T = tuple<int, int, int>;
        queue<T> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    // vis[i][j]=1;
                    q.push({i, j, 0});
                    minDist[i][j] = 0;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto [row, col, steps] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && minDist[nRow][nCol] == -1)
                {
                    // vis[nRow][nCol]=1;
                    minDist[nRow][nCol] = steps + 1;
                    q.push({nRow, nCol, steps + 1});
                }
            }
        }

        return minDist;
    }
};