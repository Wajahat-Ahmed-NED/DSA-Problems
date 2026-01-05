// Via DFS
#include <vector>
class Solution
{
private:
    bool dfs(int node, vector<int> &vis, vector<int> &inRecursion, vector<vector<int>> &edges)
    {
        vis[node] = 1;
        inRecursion[node] = 1;

        for (auto it : edges[node])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, inRecursion, edges) == true)
                {
                    return true;
                }
            }
            else if (inRecursion[it])
            {
                return true;
            }
        }

        inRecursion[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> inRecursion(V, 0);

        vector<vector<int>> adjList(V);

        for (auto i : edges)
        {
            adjList[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, inRecursion, adjList) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

//====================
// Via BFS - Very important asked in Adobe, Amazon, Flipkart etc
//====================

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
        vector<int> indegrees(V);
        for (int u = 0; u < V; u++)
        {
            for (int &v : adjList[u])
            {
                indegrees[v]++;
            }
        }

        // 2
        queue<int> q;
        int findCount = 0;
        for (int i = 0; i < V; i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
                findCount++;
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
                indegrees[v]--;
                if (indegrees[v] == 0)
                {
                    findCount++;
                    q.push(v);
                }
            }
        }
        if (V - findCount == 0)
        {
            cout << "Cycle Not Present" << endl;
        }
        else
        {
            cout << "Cycle Present" << endl;
        }
        return result;
    }
};