class Solution
{
public: // Just same as count no of subarrays with sum = k
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int prefixXOR = 0;
        int count = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixXOR ^= nums[i];
            if (m[prefixXOR ^ k])
            {
                count += m[prefixXOR ^ k];
            }
            m[prefixXOR]++;
        }

        return count;
    }
};

// Leetcode:Count the Number of Beautiful Subarrays
class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        long long count = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        long long prefixXOR = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixXOR ^= nums[i];

            int diff = prefixXOR ^ 0;

            if (m.find(diff) != m.end())
            {
                count += m[diff];
            }

            m[prefixXOR]++;
        }

        return count;
    }
};