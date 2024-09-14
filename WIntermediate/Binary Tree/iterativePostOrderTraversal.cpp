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

// Using two stacks

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<int> arr;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        TreeNode *temp;

        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();

            s2.push(temp);

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }

        while (!s2.empty())
        {
            arr.push_back(s2.top()->val);
            s2.pop();
        }

        return arr;
    }
};