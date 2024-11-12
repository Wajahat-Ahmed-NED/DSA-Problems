

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> m;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            pair<Node *, int> front = q.front();
            q.pop();

            Node *f = front.first;
            int level = front.second;

            if (!m[level])
                m[level] = f->data;

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
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends