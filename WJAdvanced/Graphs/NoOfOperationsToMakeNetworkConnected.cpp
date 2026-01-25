class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (x == parent[x])
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int components = n - 1;

        for (auto &v : connections)
        {
            int parent_x = find(v[0]);
            int parent_y = find(v[1]);

            if (parent_x != parent_y)
            {
                Union(v[0], v[1]);
                components--;
            }
        }

        return components;
    }
};

// Biweekly contest
//  Count Unreachable Pairs of Nodes in an Undirected Graph

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (x == parent[x])
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

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        // 2. joining groups
        for (auto &v : edges)
        {
            int x = v[0];
            int y = v[1];

            Union(x, y);
        }

        // 3. Filling map
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            int papaji = find(i);
            m[papaji]++;

            cout << papaji << endl;
        }

        // 4. Iterating over map
        long long result = 0;
        long long remaining = n;

        for (auto &it : m)
        {
            int size = it.second;
            result += size * (remaining - size);
            remaining -= size;
        }

        return result;
    }
};
