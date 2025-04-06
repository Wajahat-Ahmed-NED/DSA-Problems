#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adjacencyList[])
{
    int visited[n] = {0};
    visited[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adjacencyList[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}