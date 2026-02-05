class Solution
{
public:
    void dfs(vector<int> &visited, vector<int> adj[], int u)
    {
        visited[u] = 1;

        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            if (visited[*it] == 0)
            {
                dfs(visited, adj, *it);
            }
        }
    }

    bool isConnected(int V, vector<int> adj[])
    {

        vector<int> visited(V, 0);

        int startNode = 0;

        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() != 0)
            {
                startNode = i;
                break;
            }
        }

        dfs(visited, adj, startNode);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0 && adj[i].size() > 0)
                return false;
        }

        return true;
    }
    int isEulerCircuit(int V, vector<int> adj[])
    {
        // Code here
        if (isConnected(V, adj) == false)
            return 0;

        int oddCount = 0;

        for (int i = 0; i < V; i++)
        {
            if (adj[i].size() & 1)
            {
                oddCount++;
            }
        }

        if (oddCount == 2)
            return 1;
        else if (oddCount > 2)
            return 0;
        else if (oddCount == 0)
            return 2;

        // will never reach this statement
        return oddCount;
    }
};