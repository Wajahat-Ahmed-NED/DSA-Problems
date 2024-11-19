// Most Optimized Approach
// TC O(2N)
// SC O(1)
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int findCelebrity(vector<vector<int>> &mat)
{
    int top = 0;
    int down = mat.size() - 1;

    while (top < down)
    {
        if (mat[top][down] == 1)
            top += 1;
        else if (mat[down][top] == 1)
            down -= 1;
        else
        {
            top++;
            down--;
        }
    }

    if (top > down)
        return -1;

    for (int i = 0; i < mat.size(); i++)
    {
        if (top == i)
            continue;
        else if (mat[top][i] != 0 || mat[i][top] != 1)
            return -1;
    }

    return top;
}

int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    vector<vector<int>> matrix = {{0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int celebrity = findCelebrity(matrix);

    cout << "Celebrity is " << celebrity << endl;
    return 0;
}