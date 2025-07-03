#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        int l = 0, r = 0;
        int maxfreq = 0;
        int maxi = 0;
        unordered_map<char, int> m;

        while (r < s.size())
        {

            m[s[r]]++;
            maxfreq = max(maxfreq, m[s[r]]);

            if (r - l + 1 - maxfreq > k)
            {
                m[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};