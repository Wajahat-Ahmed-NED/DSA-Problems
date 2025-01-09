// Source : HackerRank
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string encryption(string s)
{
    int size = s.size();
    int rows = floor(sqrt(size));
    int cols = ceil(sqrt(size));

    if (rows * cols < size)
        rows = cols;

    vector<string> ans(cols);

    int ind = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans[j] += s[ind];
            ind++;
            if (ind == s.size())
                break;
        }
    }

    string encryptedString = "";

    for (string i : ans)
    {
        encryptedString += i;
        encryptedString += " ";
    }

    return encryptedString;
}