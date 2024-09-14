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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> arr;

        stack<TreeNode *> s;
        s.push(root);
        TreeNode *temp;

        while (!s.empty())
        {
            temp = s.top();
            s.pop();

            arr.push_back(temp->val);

            if (temp->right)
                s.push(temp->right);

            if (temp->left)
                s.push(temp->left);
        }

        return arr;
    }
};