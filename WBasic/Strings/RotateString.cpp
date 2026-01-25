class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        s = s + s;

        int i = 0;
        int j = 0;

        while (i < s.size())
        {
            if (s[i] == goal[0])
            {
                string sub = s.substr(i, goal.size());
                if (sub == goal)
                    return true;
            }
            i++;
        }

        return false;
    }
};