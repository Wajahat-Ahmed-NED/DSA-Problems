class Solution
{
public:
    int beautySum(string s)
    {
        unordered_map<char, int> m;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sum = 0;

        for (int i = 0; i < s.size(); i++)
        {
            maxi = INT_MIN;
            m.clear();
            m[s[i]]++;
            maxi = max(maxi, m[s[i]]);

            for (int j = i + 1; j < s.size(); j++)
            {
                mini = INT_MAX;
                m[s[j]]++;
                maxi = max(maxi, m[s[j]]);

                for (auto &it : m)
                {
                    mini = min(mini, it.second);
                }

                sum += maxi - mini;
            }
        }

        return sum;
    }
};