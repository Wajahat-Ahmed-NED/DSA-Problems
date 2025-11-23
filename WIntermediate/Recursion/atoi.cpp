class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 1;
        int ans = 0;

        while (i < s.size() && s[i] == ' ')
            i++;

        if (i < s.size())
        {
            sign = s[i] == '-' ? -1 : 1;
            if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            else if (s[i] == '+')
            {
                sign = 1;
                i++;
            }
        }

        while (i < s.size() && s[i] == '0')
            i++;

        while (i < s.size() && isdigit(s[i]))
        {
            if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && s[i] > '7')
                return sign == 1 ? INT_MAX : INT_MIN;
            // else if(ans<=INT_MAX/10)
            ans = ans * 10 + (s[i] - '0');

            i++;
        }

        return ans * sign;
    }
};