bool pathSum(TreeNode *root, int target, int prevSum)
{
    if (!root)
        return false;
    else if (!root->right && !root->left)
        return prevSum + root->val == target;

    prevSum += root->val;
    bool left = pathSum(root->left, target, prevSum);
    bool right = pathSum(root->right, target, prevSum);

    return left || right;
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    int prevSum = 0;
    return pathSum(root, targetSum, prevSum);
}

// Another Approach

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
    bool inorder(TreeNode *root, int targetSum, int prevSum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            return prevSum + root->val == targetSum;
        }

        bool isLeftPresent = inorder(root->left, targetSum, prevSum + root->val);
        bool isRightPresent = inorder(root->right, targetSum, prevSum + root->val);

        return isLeftPresent || isRightPresent;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        // if(root->left==nullptr && root->right==nullptr) return targetSum==root->val;
        return inorder(root, targetSum, 0);
    }
};