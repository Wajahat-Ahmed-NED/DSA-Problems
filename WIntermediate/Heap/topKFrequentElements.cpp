#include <unordered_map>
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;

        for (auto i : nums)
        {
            map[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int cnt = 0;

        for (const auto &i : map)
        {
            if (cnt < k)
            {
                pq.push({i.second, i.first});
                cnt++;
            }
            else
            {
                if (pq.top().first < i.second)
                {
                    pq.pop();
                    pq.push({i.second, i.first});
                }
            }
        }

        vector<int> ans;

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};