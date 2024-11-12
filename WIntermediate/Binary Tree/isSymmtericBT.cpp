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

// My Approach
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL || (root->right == NULL && root->left == NULL))
            return true;

        queue<TreeNode *> ql;
        queue<TreeNode *> qr;

        ql.push(root->left);
        qr.push(root->right);

        while (!ql.empty())
        {

            int size = ql.size();
            int i = 0;

            while (i < size)
            {
                TreeNode *top1 = ql.front();
                TreeNode *top2 = qr.front();

                if (!(top1 != NULL ^ top2 != NULL))
                {

                    if (top1 != NULL && top2 != NULL)
                    {
                        if (top1->val != top2->val)
                            return false;

                        ql.push(top1->left);
                        ql.push(top1->right);

                        qr.push(top2->right);
                        qr.push(top2->left);
                    }
                }
                else
                    return false;

                ql.pop();
                qr.pop();
                i++;
            }
        }

        return true;
    }
};

// Optimized Approach

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
    bool checkSymmetry(TreeNode *left, TreeNode *right)
    {

        if (left == NULL || right == NULL)
            return left == right;

        return (left->val == right->val) && checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {

        if (root == NULL)
            return true;

        return checkSymmetry(root->left, root->right);
    }
};