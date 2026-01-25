class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int parent_x = parent[x];
        int parent_y = parent[y];

        if (parent_x == parent_y)
            return;

        if (rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if (rank[parent_y] > rank[parent_x])
        {
            parent[parent_x] = parent_y;
        }
        else
        {
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        rank.resize(26, 0);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }

        for (string &u : equations)
        {
            if (u[1] == '=')
            { // a==b
                int x = u[0] - 'a';
                int y = u[3] - 'a';

                Union(x, y);
            }
        }

        for (string &u : equations)
        {
            if (u[1] == '!')
            { // a!=b
                char x = u[0] - 'a';
                char y = u[3] - 'a';

                int parent_first = find(x);
                int parent_second = find(y);

                if (parent_first == parent_second)
                    return false;
            }
        }

        return true;
    }
};