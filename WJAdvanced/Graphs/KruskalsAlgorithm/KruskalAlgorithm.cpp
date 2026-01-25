class Solution
{
public:
    vector<int> rank;
    vector<int> parent;

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

    int kruskal(vector<vector<int>> &edges)
    {

        int sum = 0;
        // O(E* (4 Alpha))
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v)
            {
                Union(u, v);
                sum += w;
            }
        }

        return sum;
    }

    int spanningTree(int V, vector<vector<int>> &edges)
    {
        rank.resize(V, 0);
        parent.resize(V);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        auto comparator = [&](vector<int> &vec1, vector<int> &vec2)
        {
            return vec1[2] < vec2[2];
        };
        // O(ElogE)
        sort(edges.begin(), edges.end(), comparator);

        return kruskal(edges);
    }
};