// via BFS
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> directions{{1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

        if (n == 0 || m == 0 || grid[0][0] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int level = 0;

        while (!q.empty())
        {
            int N = q.size();

            while (N--)
            {
                auto p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                if (x == n - 1 && y == m - 1)
                    return level + 1;

                for (auto dir : directions)
                {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && grid[x_][y_] == 0)
                    {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }

            level++;
        }

        return -1;
    }
};

// via Dijkstera Algorithm // Can also be done via queue, just replace priority queue with normal queue, thats it.

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        typedef pair<int, pair<int, int>> P;

        int n = grid.size();
        int m = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] == 1)
            return -1;

        vector<vector<int>> directions{{1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty())
        {
            int d = pq.top().first;
            pair<int, int> p = pq.top().second;
            int x = p.first;
            int y = p.second;

            pq.pop();

            for (auto dir : directions)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                int currd = d + 1;
                // cout<<x_<<" "<<y_<<" "<<n<<" "<<m<<endl;
                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && grid[x_][y_] == 0 && currd < result[x_][y_])
                {
                    pq.push({currd, {x_, y_}});
                    grid[x_][y_] = 1;
                    result[x_][y_] = currd;
                }
            }
        }

        if (result[n - 1][m - 1] == INT_MAX)
            return -1;

        return result[n - 1][m - 1] + 1;
    }
};