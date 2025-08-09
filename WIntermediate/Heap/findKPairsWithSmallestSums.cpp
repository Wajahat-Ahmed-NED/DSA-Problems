// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
//  BruteForce Approch
// TC= O(n*m*logk) SC=O(n*m)

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        priority_queue<pair<int, vector<int>>> pq;

        for (int i : nums1)
        {
            for (int j : nums2)
            {
                pq.push({i + j, {i, j}});
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }

        vector<vector<int>> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

// Optimized Approach
// TC: O(k log k), SC: O(k)

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> result;
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        for (int i = 0; i < nums1.size() && i < k; i++)
        {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        while (!minHeap.empty() && result.size() < k)
        {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size())
            {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};
