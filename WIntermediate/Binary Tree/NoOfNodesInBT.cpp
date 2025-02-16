/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// It is a complete binary tree;
// TC is O(logn^2);
// SC is O(1);// If not considering the recursion stack
// SC is O(logn);// If considering the recursion stack

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftDepth = 0;
        TreeNode *left = root;
        while (left)
        {
            left = left->left;
            leftDepth++;
        }

        int rightDepth = 0;
        TreeNode *right = root;
        while (right)
        {
            right = right->right;
            rightDepth++;
        }

        if (leftDepth == rightDepth)
        {
            return pow(2, leftDepth) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};