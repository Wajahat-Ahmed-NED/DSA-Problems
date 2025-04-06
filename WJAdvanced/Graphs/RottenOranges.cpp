#include <bits/stdc++.h>
using namespace std;
// Problem: https://leetcode.com/problems/rotting-oranges/description/
// Approach: BFS

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        // {{i,j},t}
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                }

                if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        int time = 0; // up,down,left,right
        int rowsUtil[4] = {-1, 1, 0, 0};
        int colsUtil[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currentTime = q.front().second;
            q.pop();
            time = max(time, currentTime);

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + rowsUtil[i];
                int ncol = col + colsUtil[i];

                if (nrow < rows && nrow >= 0 && ncol >= 0 && ncol < cols && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, currentTime + 1});
                    visited[nrow][ncol] = 2;
                    freshOranges--;
                }
            }
        }

        if (freshOranges != 0)
            return -1;

        return time;
    }
};