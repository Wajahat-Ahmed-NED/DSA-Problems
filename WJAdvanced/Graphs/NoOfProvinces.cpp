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

// via BFS
class Solution
{
public:
    void bfs(int u, vector<int> &visited, unordered_map<int, vector<int>> &adjList)
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
                if (!visited[v])
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        // for(int &v:adjList[u]){
        //     if(!visited[v]){
        //         bfs(v,visited,adjList);
        //     }
        // }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m = isConnected[0].size();

        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited, adjList);
                count++;
            }
        }

        return count;
    }
};

// using given matrix - BFS

class Solution
{
public:
    void bfs(int u, vector<int> &visited, vector<vector<int>> &isConnected, int cols)
    {
        queue<int> q;
        q.push(u);
        visited[u] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // for(int &v:adjList[u]){
            //     if(!visited[v]){
            //         visited[v]=1;
            //         q.push(v);
            //     }
            // }

            for (int v = 0; v < cols; v++)
            {
                if (!visited[v] && isConnected[u][v] == 1)
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        // for(int &v:adjList[u]){
        //     if(!visited[v]){
        //         bfs(v,visited,adjList);
        //     }
        // }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m = isConnected[0].size();

        // unordered_map<int,vector<int>> adjList;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<m;j++){
        //         if(i!=j && isConnected[i][j]==1){
        //             adjList[i].push_back(j);
        //             adjList[j].push_back(i);
        //         }
        //     }
        // }

        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bfs(i, visited, isConnected, m);
                count++;
            }
        }

        return count;
    }
};