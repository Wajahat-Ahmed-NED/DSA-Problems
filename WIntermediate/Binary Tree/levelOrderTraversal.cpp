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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> arr;
        vector<int> tempArr;
        int size;
        //  front;

        while (!q.empty())
        {
            size = q.size();
            tempArr.clear();

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                tempArr.push_back(front->val);
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            arr.push_back(tempArr);
        }

        return arr;
    }
};