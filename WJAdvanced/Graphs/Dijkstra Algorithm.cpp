// Via set - Can also be done via priority Queue - Do it here also
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        set<pair<int, int>> st;

        unordered_map<int, vector<pair<int, int>>> m;

        for (auto &v : edges)
        {
            m[v[0]].push_back({v[2], v[1]});
            m[v[1]].push_back({v[2], v[0]});
        }

        vector<int> result(V, INT_MAX);
        result[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto &it = *st.begin();

            int d = it.first;
            int n = it.second;

            st.erase(it);

            for (auto &v : m[n])
            {
                int dist = v.first;
                int nNode = v.second;
                if (d + dist < result[nNode])
                {
                    if (result[nNode] != INT_MAX)
                    {
                        st.erase({result[nNode], nNode});
                    }

                    result[nNode] = d + dist;
                    st.insert({result[nNode], nNode});
                }
            }
        }

        return result;
    }
};