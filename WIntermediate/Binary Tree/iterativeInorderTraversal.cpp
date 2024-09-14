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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<int> arr;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *node = root->left;

        while (true)
        {
            if (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    break;
                node = s.top();
                s.pop();
                arr.push_back(node->val);
                node = node->right;
            }
        }

        return arr;
    }
};