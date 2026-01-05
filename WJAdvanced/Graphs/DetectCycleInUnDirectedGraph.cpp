class Solution
{
public:
    bool BFS(int u, vector<int> &visited, vector<vector<int>> &edges)
    {
        visited[u] = 1;
        queue<pair<int, int>> q;
        q.push({u, -1});

        while (!q.empty())
        {
            pair<int, int> P = q.front();
            q.pop();

            int node = P.first;
            int parent = P.second;

            for (int &v : edges[node])
            {
                //   visited[v]=true;
                if (v == parent)
                    continue;
                if (visited[v] == 1)
                    return true;
                else
                {
                    visited[v] = 1;
                    q.push({v, node});
                }
            }
        }

        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (BFS(i, visited, edges))
                    return true;
            }
        }

        return false;
    }
};

//<======Using DFS======>
class Solution
{
public:
    bool DFS(int u, vector<int> &visited, vector<vector<int>> &edges, int parent)
    {
        visited[u] = 1;

        for (int &v : edges[u])
        {
            if (v == parent)
                continue;
            if (visited[v])
                return true;
            else
            {
                if (DFS(v, visited, edges, u) == true)
                    return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (DFS(i, visited, edges, -1))
                    return true;
            }
        }

        return false;
    }
};
