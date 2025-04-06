#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void depthFirstSearch(int nodes, unordered_map<int, int> &vis, vector<int> &ls, vector<vector<int>> &adj)
    {
        ls.push_back(nodes);
        vis[nodes] = 1;

        for (auto it : adj[nodes])
        {
            if (!vis[it])
            {
                depthFirstSearch(it, vis, ls, adj);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here

        int nodes = 0;
        unordered_map<int, int> vis;
        vector<int> ls;

        depthFirstSearch(nodes, vis, ls, adj);

        return ls;
    }
};