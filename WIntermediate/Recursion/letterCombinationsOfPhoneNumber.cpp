#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findAllCombinations(int ind, string &digit, vector<string> &strings, string &temp, vector<string> &result)
    {
        if (ind == digit.size())
        {
            result.push_back(temp);
            return;
        }
        string nums = strings[(digit[ind] - '0') - 2];
        for (int i = 0; i < nums.size(); i++)
        {
            temp = temp + nums[i];
            findAllCombinations(ind + 1, digit, strings, temp, result);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        string temp;
        vector<string> strings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        findAllCombinations(0, digits, strings, temp, result);

        return result;
    }
};