class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        m[0] = 1;
        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            int diff = prefixSum - k;

            if (m[diff])
            {
                count += m[diff];
            }

            m[prefixSum]++;
        }

        return count;
    }
};

// To print those subarrays
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> m;
        m[0] = {-1};
        int prefixSum = 0;
        int count = 0;
        vector

            for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            int diff = prefixSum - k;

            if (m[diff])
            {
                count += m[diff].size();
                for (auto prevInd : m[diff])
                {
                    ans.push_back({prevInd + 1, i});
                }
            }

            m[prefixSum].push_back(i);
        }

        return count;
    }
};

// Subarray with equal no of ones and zeros
int main()
{
    string s = "00000010010010";
    int l = 0;
    int r = 0;
    unordered_map<int, int> m;
    m[0] = -1;

    while (r < s.size())
    {
        if (s[r] == 0)
            sum -= 1;
        else
            sum += 1;

        // Optional, dont do if m[0]=-1 (done above)
        // if (sum == 0)
        // {
        //     maxi = max(maxi, r + 1);
        // }

        if (m[sum - 0])
        {
            int isPresent = m[sum - 0];
            maxi = max(i - isPresent, maxi);
        }

        if (!m[sum])
        {
            m[sum] = i;
        }

        r++;
    }
}