/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.

    TreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    TreeNode *leftTree = temp->left;

    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode *rightTree = temp->right;

    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    // cout<<pred<<" "<<success<<endl;
    return {pred, succ};
}

// More Optimized Approach
TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;

    while (root != NULL)
    {
        if (root->val > p->val)
        {
            successor = root;
            root = root->left;
        }
        else if (root->val <= p->val)
        {
            root = root->right;
        }
    }

    return successor;
}

TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p)
{
    TreeNode *pred = NULL;

    while (root != NULL)
    {
        if (root->val >= p->val)
            root = root->left;

        else if (root->val < p->val)
        {
            pred = root;
            root = root->right;
        }
    }

    return pred;
}