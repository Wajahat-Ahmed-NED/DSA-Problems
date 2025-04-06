#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void convertAdjMatrixToAdjList(vector<vector<int>> &adjList, vector<vector<int>> &isConnected, int size)
    {

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
    }

    void depthFirstSearch(int node, vector<vector<int>> &adjList, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adjList[node])
        {
            if (!vis[it])
                depthFirstSearch(it, adjList, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int size = isConnected.size();
        vector<vector<int>> adjList(size);

        convertAdjMatrixToAdjList(adjList, isConnected, size);

        vector<int> vis(size, 0);
        int cnt = 0;

        for (int i = 0; i < size; i++)
        {
            if (!vis[i])
            {
                cnt++;
                depthFirstSearch(i, adjList, vis);
            }
        }

        return cnt;
    }
};