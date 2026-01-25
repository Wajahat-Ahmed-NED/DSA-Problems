class Solution
{
public:
    string largestOddNumber(string num)
    {

        int s = -1;
        for (int i = 0; i < num.size(); i++)
        {
            if ((num[i] - '0') & 1)
            {
                s = i;
            }
        }

        if (s == -1)
            return "";
        return num.substr(0, s + 1);
    }
};