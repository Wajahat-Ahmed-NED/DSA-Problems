map<int, int> m;
queue<pair<Node *, int>> q;
q.push({root, 0});

while (!q.empty())
{
    pair<Node *, int> front = q.front();
    q.pop();

    Node *f = front.first;
    int level = front.second;

    m[level] = f->data; // Only this line is changed else is same as the top level view

    if (f->left)
        q.push({f->left, level - 1});
    if (f->right)
        q.push({f->right, level + 1});
}

vector<int> res;

for (auto i : m)
{
    res.push_back(i.second);
}

return res;