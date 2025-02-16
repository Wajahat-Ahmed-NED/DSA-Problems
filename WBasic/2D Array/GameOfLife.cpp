#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));
        int cnt = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cnt = 0;
                // For Sides
                if (j - 1 >= 0 && board[i][j - 1] == 1)
                    cnt++;
                if (i - 1 >= 0 && board[i - 1][j] == 1)
                    cnt++;
                if (j + 1 < cols && board[i][j + 1] == 1)
                    cnt++;
                if (i + 1 < rows && board[i + 1][j] == 1)
                    cnt++;

                // For Diagonals
                if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
                    cnt++;
                if (i - 1 >= 0 && j + 1 < cols && board[i - 1][j + 1] == 1)
                    cnt++;
                if (i + 1 < rows && j - 1 >= 0 && board[i + 1][j - 1] == 1)
                    cnt++;
                if (i + 1 < rows && j + 1 < cols && board[i + 1][j + 1] == 1)
                    cnt++;

                if (board[i][j] == 1)
                {
                    if (cnt < 2)
                        ans[i][j] = 0;
                    else if (cnt <= 3)
                        ans[i][j] = 1;
                    else if (cnt > 3)
                        ans[i][j] = 0;
                    else
                    {
                        ans[i][j] = board[i][j];
                    }
                }
                else
                {
                    if (cnt == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }

        board = ans;
    }
};