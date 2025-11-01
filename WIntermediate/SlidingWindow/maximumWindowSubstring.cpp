// Optimized Way: To use vector but map can also be used but less fast

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sLen = s.size();
        int tLen = t.size();

        if (sLen < tLen)
            return "";

        int r = 0;
        int l = 0;
        int cnt = INT_MAX;
        vector<int> resultIndex = {0, 0};

        // unordered_map<char,int> m;
        vector<int> freq(256, 0);

        for (auto i : t)
        {
            freq[i]++;
        }

        int count = tLen;

        while (r < sLen)
        {
            // if(m.find(s[r])!=m.end()){
            if (freq[s[r]] > 0)
                count--;
            freq[s[r]]--;
            // }

            while (l < sLen && count == 0)
            {
                int currLen = r - l + 1;

                if (currLen < cnt)
                {
                    cnt = currLen;
                    resultIndex[0] = l;
                    resultIndex[1] = currLen;
                }

                // if(m.find(s[l])!=m.end()) {
                freq[s[l]]++;
                if (freq[s[l]] > 0)
                    count++;
                // }

                l++;
            }
            r++;
        }

        return s.substr(resultIndex[0], resultIndex[1]);
    }
};