// Better Apporach O(2^2n * 2n)

class Solution
{
public:
    vector<string> result;

    bool isValid(string &str, int n)
    {
        int cnt = 0;

        for (auto i : str)
        {
            if (i == '(')
                cnt++;
            else
                cnt--;

            if (cnt < 0)
                return false;
        }

        return cnt == 0;
    }

    void solve(string &str, int n)
    {
        if (str.length() == n)
        {
            if (isValid(str, n))
            {
                result.push_back(str);
            }
            return;
        }

        str.push_back('(');
        solve(str, n);
        str.pop_back();

        str.push_back(')');
        solve(str, n);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n)
    {
        string str = "";
        solve(str, 2 * n);

        return result;
    }
};

// Optimized Approach O(2^2n)
class Solution
{
public:
    vector<string> result;

    void solve(string &str, int n, int open, int close)
    {
        if (str.length() == 2 * n)
        {
            result.push_back(str);
            return;
        }

        if (open < n)
        {
            open++;
            str.push_back('(');
            solve(str, n, open, close);
            str.pop_back();
            open--;
        }

        if (close < open)
        {
            close++;
            str.push_back(')');
            solve(str, n, open, close);
            str.pop_back();
            close--;
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string str = "";
        int open = 0;
        int close = 0;
        solve(str, n, open, close);

        return result;
    }
};