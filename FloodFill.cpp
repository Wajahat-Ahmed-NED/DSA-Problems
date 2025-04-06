#include <bits/stdc++.h>
using namespace std;

// using DFS

class Solution
{
private:
    void depthFirstSearch(int row, int col, int initialColor, int color, vector<vector<int>> &image, vector<vector<int>> &result, int delRow[], int delCol[])
    {

        result[row][col] = color;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && result[nrow][ncol] != color)
            {
                depthFirstSearch(nrow, ncol, initialColor, color, image, result, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        vector<vector<int>> result = image;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        depthFirstSearch(sr, sc, initialColor, color, image, result, delRow, delCol);

        return result;
    }
};

// using BFS

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int rows = image.size();
        int cols = image[0].size();

        vector<vector<int>> result(rows);

        for (int row = 0; row < rows; row++)
        {
            result[row] = image[row];
        }

        queue<pair<int, int>> q;
        q.push({sr, sc});

        int initialColor = image[sr][sc];
        result[sr][sc] = color;
        //{u,p,l,r}
        int rowUtils[4] = {-1, 1, 0, 0};
        int colUtils[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + rowUtils[i];
                int ncol = col + colUtils[i];

                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && result[nrow][ncol] != color && image[nrow][ncol] == initialColor)
                {
                    result[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return result;
    }
};