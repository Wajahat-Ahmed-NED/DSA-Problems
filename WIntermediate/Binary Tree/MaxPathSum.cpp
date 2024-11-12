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
class Solution
{
public:
    int findHeight(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return 0;

        int left = max(0, findHeight(root->left, sum));
        int right = max(0, findHeight(root->right, sum));

        sum = max(sum, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        findHeight(root, sum);
        return sum;
    }
};
