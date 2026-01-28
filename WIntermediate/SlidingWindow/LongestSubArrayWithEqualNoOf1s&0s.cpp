class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> m;
        m[0] = -1;
        int prefixSum = 0;
        // int count=0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                prefixSum -= 1;
            else
                prefixSum += 1;

            int diff = prefixSum - 0;

            if (m.find(diff) != m.end())
            {
                // cout<<m[diff]<<" ";
                int isPresent = m[diff];
                maxi = max(maxi, i - isPresent);
            }
            // else m[prefixSum]=i;
            // cout<<prefixSum<<endl;
            // if(!m[prefixSum]){
            if (m.find(prefixSum) == m.end())
            {
                cout << prefixSum << " " << i << endl;
                m[prefixSum] = i;
            }
        }

        return maxi;
    }
};