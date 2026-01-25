class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        int open = 0;
        int close = 0;
        int st = 0;
        int e = s.size() - 1;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (open == 0)
                st = i;
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                close++;

            if (open == close)
            {
                e = i - 1;
                ans += s.substr(st + 1, e - st);
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
};