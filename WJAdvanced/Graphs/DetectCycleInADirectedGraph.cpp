#include <vector>
class Solution
{
private:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &edges)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : edges[node])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, pathVis, edges) == true)
                {
                    return true;
                }
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        vector<vector<int>> adjList(V);

        for (auto i : edges)
        {
            adjList[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, pathVis, adjList) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};