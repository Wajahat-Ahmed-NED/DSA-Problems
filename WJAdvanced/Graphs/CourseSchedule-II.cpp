class Solution
{
public:
    vector<int> kahnsAlgorithm(int numCourses, unordered_map<int, vector<int>> &adjList, vector<int> &indegrees)
    {
        queue<int> q;
        int count = 0;
        vector<int> result;
        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
                result.push_back(i);
                count++;
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int &v : adjList[u])
            {
                indegrees[v]--;
                if (indegrees[v] == 0)
                {
                    q.push(v);
                    result.push_back(v);
                    count++;
                }
            }
        }

        if (count == numCourses)
        {
            return result;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegrees(numCourses, 0);

        for (auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];

            adjList[b].push_back(a);
            indegrees[a]++;
        }

        return kahnsAlgorithm(numCourses, adjList, indegrees);
    }
};