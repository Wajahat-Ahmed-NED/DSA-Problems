class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here

        vector<vector<int>> adjList(V);

        for (auto i : edges)
        {
            adjList[i[0]].push_back(i[1]);
        }

        // 1
        vector<int> inDegrees(V);

        for (int u = 0; u < V; u++)
        {
            for (int &v : adjList[u])
            {
                inDegrees[v]++;
            }
        }

        // 2
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (inDegrees[i] == 0)
            {
                q.push(i);
            }
        }

        // 3
        vector<int> result;
        while (!q.empty())
        {
            int u = q.front();
            result.push_back(u);
            q.pop();

            for (int &v : adjList[u])
            {
                inDegrees[v]--;
                if (inDegrees[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return result;
    }
};