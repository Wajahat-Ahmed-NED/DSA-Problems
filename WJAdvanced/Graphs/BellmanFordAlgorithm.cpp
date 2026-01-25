// User function Template for C++

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<int> result(V, 1e8);
        result[src] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (result[u] != 1e8 && w + result[u] < result[v])
                {
                    result[v] = w + result[u];
                }
            }
        }

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (result[u] != 1e8 && w + result[u] < result[v])
            {
                return {-1};
            }
        }

        return result;
    }
};
