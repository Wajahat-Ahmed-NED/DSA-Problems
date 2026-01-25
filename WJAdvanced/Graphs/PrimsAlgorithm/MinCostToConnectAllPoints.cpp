class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {

        // Can also create adjList and calculate distance with each node,
        // store in unordered_map and then just call prims algorithm
        // Sir MIK used this approach
        typedef vector<int> P;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        vector<bool> isMST(points.size(), false);
        int sum = 0;
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();

            int w = p[0];
            int ind = p[1];
            int x = points[ind][0];
            int y = points[ind][1];

            if (isMST[ind])
                continue;

            isMST[ind] = true;

            sum += w;
            int i = 0;
            for (auto edge : points)
            {
                int _x = edge[0];
                int _y = edge[1];
                int ind = i++;
                int d = abs(x - _x) + abs(y - _y); // Manhattan Distance Formula

                if (isMST[ind] == false)
                {
                    pq.push({d, ind});
                }
            }
        }

        return sum;
    }
};