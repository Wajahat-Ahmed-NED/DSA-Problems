// Leetcode Solution: https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {

            if (matrix[row][col] == target)
            {
                return target;
            }
            else if (matrix[row][col] > target)
            {
                col -= 1;
            }
            else
            {
                row += 1;
            }
        }

        return false;
    }
};