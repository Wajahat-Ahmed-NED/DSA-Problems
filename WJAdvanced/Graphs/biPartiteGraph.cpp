class Solution
{
private:
    bool dfs(vector<vector<int>> &graph, int row, int color, vector<int> &colorTrack)
    {

        colorTrack[row] = color;

        for (int i = 0; i < graph[row].size(); i++)
        {
            if (colorTrack[graph[row][i]] == -1)
            {
                if (dfs(graph, graph[row][i], !color, colorTrack) == false)
                    return false;
            }
            if (colorTrack[graph[row][i]] == color)
                return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<int> colorTrack(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (colorTrack[i] == -1)
            {
                if (dfs(graph, i, 0, colorTrack) == false)
                    return false;
            }
        }

        return true;
    }
};

// <=== Second Practice ====>

class Solution
{
public:
    bool dfs(int u, vector<vector<int>> &adjList, vector<int> &visited, int color)
    {
        visited[u] = color;

        for (int &v : adjList[u])
        {
            if (visited[v] == -1)
            {
                if (dfs(v, adjList, visited, !color) == false)
                    return false;
            }
            else if (visited[v] == color)
                return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        // unordered_map<int,vector<int>> adjList;
        vector<int> visited(graph.size(), -1);

        // for(int i=0;i<graph.size();i++){
        //     for(int j=0;j<graph[i].size();j++){
        //         adjList[i].push_back(graph[i][j]);
        //     }
        // }

        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == -1)
            {
                int color = 1;
                if (dfs(i, graph, visited, color) == false)
                    return false;
            }
        }

        return true;
    }
};

// <====Via BFS====>

class Solution
{
public:
    bool bfs(int u, vector<vector<int>> &adjList, vector<int> &visited)
    {
        queue<int> q;
        q.push(u);
        visited[u] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int &v : adjList[u])
            {
                if (visited[v] == -1)
                {
                    visited[v] = !visited[u];
                    q.push(v);
                }
                else if (visited[v] == visited[u])
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        // unordered_map<int,vector<int>> adjList;
        vector<int> visited(graph.size(), -1);

        // for(int i=0;i<graph.size();i++){
        //     for(int j=0;j<graph[i].size();j++){
        //         adjList[i].push_back(graph[i][j]);
        //     }
        // }

        for (int i = 0; i < graph.size(); i++)
        {
            if (visited[i] == -1)
            {
                if (bfs(i, graph, visited) == false)
                    return false;
            }
        }

        return true;
    }
};