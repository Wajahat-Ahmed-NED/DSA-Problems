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