// Asked In Meta

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
            return;

        if (rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if (rank[parent_y] > rank[parent_x])
        {
            parent[parent_x] = parent_y;
        }
        else
        {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int kruskalAlgo(vector<vector<int>> &adjList)
    {
        int sum = 0;

        for (auto edge : adjList)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u == parent_v)
                continue;

            Union(u, v);
            sum += w;
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<vector<int>> adjList;
        int n = points.size();
        int m = points[0].size();

        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int _x = points[j][0];
                int _y = points[j][1];

                int d = abs(x - _x) + abs(y - _y);

                adjList.push_back({i, j, d});
            }
        }

        auto comparator = [&](vector<int> &v1, vector<int> &v2)
        {
            return v1[2] < v2[2];
        };
        sort(adjList.begin(), adjList.end(), comparator);

        return kruskalAlgo(adjList);
    }
};