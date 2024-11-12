int findRes(Node *root, int input, int ceils)
{
    if (root == NULL)
        return ceils == INT_MAX ? -1 : ceils;

    int ans; // Can also do without using ans variable

    if (root->data == input)
        return root->data;
    else if (root->data > input)
    {
        ceils = min(ceils, root->data);

        ans = findRes(root->left, input, ceils);
    }
    else
        ans = findRes(root->right, input, ceils);

    return ans;
}

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    return findRes(root, input, INT_MAX);
}

// Iterative solution

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    int ceils = -1;

    while (root)
    {
        if (root->data == input)
        {
            ceils = root->data;
            return ceils;
        }

        if (root->data < input)
            root = root->right;
        else
        {
            ceils = root->data;
            root = root->left;
        }
    }

    return ceils;
}