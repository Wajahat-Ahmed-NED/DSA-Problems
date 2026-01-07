class Solution
{
public:
    bool kahnsAlgorithm(int numCourses, unordered_map<int, vector<int>> &adjList, vector<int> &indegrees)
    {
        queue<int> q;
        int count = 0;

        for (int i = 0; i < indegrees.size(); i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
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
                    count++;
                }
            }
        }

        return count == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adjList;
        int n = prerequisites.size();
        vector<int> indegrees(numCourses, 0);
        // b-->a
        for (int i = 0; i < n; i++)
        {
            int b = prerequisites[i][1];
            int a = prerequisites[i][0];
            adjList[b].push_back(a);

            indegrees[a]++;
        }

        return kahnsAlgorithm(numCourses, adjList, indegrees);
    }
};

//<========== Via DFS ==========>

class Solution
{
public:
    bool isCyclePresent(int u, vector<int> &visited, unordered_map<int, vector<int>> &adjList, vector<int> &inRecursion)
    {
        visited[u] = 1;
        inRecursion[u] = 1;

        for (auto &v : adjList[u])
        {
            if (!visited[v])
            {
                if (isCyclePresent(v, visited, adjList, inRecursion))
                    return true;
            }
            else if (inRecursion[v])
                return true;
        }

        inRecursion[u] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adjList;
        int n = prerequisites.size();
        vector<int> inRecursion(numCourses, 0);
        vector<int> visited(numCourses, 0);

        // b-->a
        for (int i = 0; i < n; i++)
        {
            int b = prerequisites[i][1];
            int a = prerequisites[i][0];
            adjList[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (isCyclePresent(i, visited, adjList, inRecursion))
                    return false; // means you can't complete the course
            }
        }

        // means you can complete the course
        return true;
    }
};