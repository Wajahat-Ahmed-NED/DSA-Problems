class Solution
{
public:
    bool DFS(int u, vector<int> &visited, stack<int> &s, vector<vector<int>> &adjList, vector<int> &isRecursion)
    {
        visited[u] = 1;
        isRecursion[u] = 1; // No need for it during traversal, used only when detecting cycle in Cyclic Directed Graph

        for (int &v : adjList[u])
        {
            if (!visited[v])
            {
                DFS(v, visited, s, adjList, isRecursion);
            }
            else if (isRecursion[v])
                return true;
        }

        isRecursion[u] = 0;
        s.push(u);
        return false;
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<int> visited(V, 0);
        vector<int> isRecursion(V, 0); // No need for it during traversal, used only when detecting cycle in Cyclic Directed Graph
        vector<int> ans;

        stack<int> s;
        vector<vector<int>> adjList(V);

        for (auto i : edges)
        {
            adjList[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, visited, s, adjList, isRecursion);
            }
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};