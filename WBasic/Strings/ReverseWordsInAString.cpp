class Solution
{
public:
    string reverseWords(string s)
    {

        int i = s.size() - 1;
        string ans = "";
        int left = 0;
        int right = 0;

        while (i >= 0)
        {
            while (i >= 0 && s[i] == ' ')
                i--;

            right = i;

            while (i >= 0 && s[i] != ' ')
                i--;

            left = i + 1;

            ans += s.substr(left, right - left + 1);

            ans += ' ';
        }

        i = ans.size() - 1;

        while (ans[i--] == ' ')
            ans.pop_back();

        return ans;
    }
};