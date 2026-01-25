// Via Dijkstra Algorithm
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        typedef pair<int, pair<int, int>> P;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty())
        {
            int diff = pq.top().first;
            auto p = pq.top().second;
            pq.pop();

            int x = p.first;
            int y = p.second;

            // if(x==n-1 && y==m-1) return diff; //Optional came to know after dry run

            for (auto dir : directions)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m)
                {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);
                    if (maxDiff < result[x_][y_])
                    {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }

        return result[n - 1][m - 1];
    }
};