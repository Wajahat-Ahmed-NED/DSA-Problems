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
    bool inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return true;

        bool left = inorder(root->left, arr);

        if (arr.size() > 0)
        {
            if (arr[arr.size() - 1] >= root->val)
            {
                return false;
            }
        }

        arr.push_back(root->val);

        bool right = inorder(root->right, arr);

        return left && right;
    }
    bool isValidBST(TreeNode *root)
    {
        vector<int> arr;
        return inorder(root, arr);
    }
};