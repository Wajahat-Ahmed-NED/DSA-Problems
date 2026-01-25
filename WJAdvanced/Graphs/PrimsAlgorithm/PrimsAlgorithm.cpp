class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // code here
        typedef pair<int, int> P;

        unordered_map<int, vector<vector<int>>> adjList;

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back({edge[2], edge[1]});
            adjList[edge[1]].push_back({edge[2], edge[0]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0});

        vector<bool> isMST(V, false);

        int sum = 0;

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int w = p.first;
            int n = p.second;

            if (isMST[n])
                continue;

            isMST[n] = true;

            sum += w;

            for (auto edge : adjList[n])
            {
                int neighbourWt = edge[0];
                int neighbourNode = edge[1];

                if (isMST[neighbourNode] == false)
                {
                    pq.push({neighbourWt, neighbourNode});
                }
            }
        }

        return sum;
    }
};

// With Parent

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // code here
        typedef vector<int> P;

        unordered_map<int, vector<vector<int>>> adjList;

        for (auto edge : edges)
        {
            adjList[edge[0]].push_back({edge[2], edge[1]});
            adjList[edge[1]].push_back({edge[2], edge[0]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, 0});

        vector<bool> isMST(V, false);
        vector<int> parent(V, -1);

        int sum = 0;

        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int w = p[0];
            int n = p[1];
            int pa = p[2];

            if (isMST[n])
                continue;

            isMST[n] = true;
            parent[n] = p;
            sum += w;

            for (auto edge : adjList[n])
            {
                int neighbourWt = edge[0];
                int neighbourNode = edge[1];

                if (isMST[neighbourNode] == false)
                {
                    pq.push({neighbourWt, neighbourNode, n});
                }
            }
        }

        return sum;
    }
};