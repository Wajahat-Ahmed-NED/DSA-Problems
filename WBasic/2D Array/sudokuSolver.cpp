// BruteForce Approach
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        int startCol = 0;
        int startRow = 0;
        unordered_map<int, int> gridMap;
        unordered_map<int, unordered_map<int, int>> rowMap;
        unordered_map<int, unordered_map<int, int>> colMap;

        while (startRow < row - 2)
        {
            while (startCol < col - 2)
            {
                // Traversing 3x3 Grid
                for (int i = startRow; i <= startRow + 2; i++)
                {
                    for (int j = startCol; j <= startCol + 2; j++)
                    {
                        if (board[i][j] != '.')
                        {
                            // For Row Checking
                            if (rowMap.find(board[i][j]) != rowMap.end())
                            {
                                if (rowMap[board[i][j]].find(i) != rowMap[board[i][j]].end())
                                {
                                    return false;
                                }
                                else
                                    rowMap[board[i][j]][i]++;
                            }
                            else
                            {
                                unordered_map<int, int> m;
                                m[i] = 1;
                                rowMap[board[i][j]] = m;
                            }

                            // For Col Checking
                            if (colMap.find(board[i][j]) != colMap.end())
                            {
                                if (colMap[board[i][j]].find(j) != colMap[board[i][j]].end())
                                {
                                    return false;
                                }
                                else
                                    colMap[board[i][j]][j]++;
                            }
                            else
                            {
                                unordered_map<int, int> m;
                                m[j] = 1;
                                colMap[board[i][j]] = m;
                            }

                            // For Grid Checking
                            if (gridMap.find(board[i][j]) != gridMap.end())
                            {
                                return false;
                            }
                            else
                                gridMap[board[i][j]]++;
                        }
                    }
                }
                startCol += 3;
                gridMap.clear();
            }
            startCol = 0;
            startRow += 3;
        }

        return true;
    }
};

// Optimized Approach

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, unordered_set<int>> rowMap;
        unordered_map<char, unordered_set<int>> colMap;
        unordered_map<int, unordered_set<char>> gridMap; // Corrected gridMap

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num = board[i][j];
                if (num == '.')
                    continue;

                // Check row for duplicates
                if (rowMap[num].find(i) != rowMap[num].end())
                    return false;
                rowMap[num].insert(i);

                // Check column for duplicates
                if (colMap[num].find(j) != colMap[num].end())
                    return false;
                colMap[num].insert(j);

                // Check 3x3 grid for duplicates
                int gridKey = (i / 3) * 3 + (j / 3); // Formula for getting the same grid
                if (gridMap[gridKey].find(num) != gridMap[gridKey].end())
                    return false;
                gridMap[gridKey].insert(num); // Insert the number in the grid's set
            }
        }

        return true;
    }
};