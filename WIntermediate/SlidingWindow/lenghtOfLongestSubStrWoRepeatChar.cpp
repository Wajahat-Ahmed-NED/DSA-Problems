class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0;
        int maxi = 0;
        unordered_map<char, int> m;

        while (r < s.size())
        {
            if (m[s[r]] && m[s[r]] - 1 >= l)
            {
                l = m[s[r]];
            }
            m[s[r]] = r + 1;
            maxi = max(r - l + 1, maxi);
            r++;
        }
        return maxi;
    }
};