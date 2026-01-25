// https : // leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

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

        // for(int u=0;u<edges.size();u++){
        //     for(int &v:edges[u]){
        //         Union(u,v);
        //     }
        // }

        for (auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];

            Union(u, v);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < parent.size(); i++)
        {
            int papa = find(i);
            m[papa]++;
        }

        int n1 = n;
        long long total = 0;
        for (auto &it : m)
        {
            long long size = it.second;
            cout << it.first << " ";
            total += size * (n1 - size);
            n1 -= size;
        }

        return total;
    }
};