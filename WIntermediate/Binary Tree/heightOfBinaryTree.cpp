#include <iostream>
using namespace std;

int findHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

int main()
{

    int ans = findHeight(node);

    return 0;
}
