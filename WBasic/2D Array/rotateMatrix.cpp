#include <iostream>
#include <vector>
using namespace std;

void matrixRotation(vector<vector<int>> matrix, int r)
{
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), -1));

    int stCol = 0;
    int enCol = matrix[0].size() - 1;
    int stRow = 0;
    int enRow = matrix.size() - 1;

    while (stRow < enRow && stCol < enCol)
    {

        vector<int> outerLayer;

        for (int i = stCol; i < enCol; i++)
            outerLayer.push_back(matrix[stRow][i]);
        for (int i = stRow; i < enRow; i++)
            outerLayer.push_back(matrix[i][enCol]);
        for (int i = enCol; i > stCol; i--)
            outerLayer.push_back(matrix[enRow][i]);
        for (int i = enRow; i > stRow; i--)
            outerLayer.push_back(matrix[i][stCol]);

        vector<int> rotatedList(outerLayer.size());
        int mod = r % outerLayer.size();
        for (int i = 0; i < outerLayer.size(); i++)
        {
            rotatedList[i] = outerLayer[(i + mod) % outerLayer.size()];
        }

        int ind = 0;
        for (int i = stCol; i < enCol; i++)
            ans[stRow][i] = rotatedList[ind++];
        for (int i = stRow; i < enRow; i++)
            ans[i][enCol] = rotatedList[ind++];
        for (int i = enCol; i > stCol; i--)
            ans[enRow][i] = rotatedList[ind++];
        for (int i = enRow; i > stRow; i--)
            ans[i][stCol] = rotatedList[ind++];

        stCol++;
        stRow++;
        enRow--;
        enCol--;
    }

    for (int row = 0; row < ans.size(); row++)
    {
        for (int col = 0; col < ans[row].size(); col++)
        {
            cout << ans[row][col] << " ";
        }
        cout << endl;
    }
}
