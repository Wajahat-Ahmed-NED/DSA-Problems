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