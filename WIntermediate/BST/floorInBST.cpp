int floor(Node *root, int input)
{
    if (root == NULL)
        return -1;

    int floors = -1;

    while (root)
    {
        if (root->data == input)
        {
            floors = root->data;
            return floors;
        }

        if (root->data > input)
            root = root->left;
        else
        {
            floors = root->data;
            root = root->right;
        }
    }

    return floors;
}