
class NodeVal
{
public:
    int maxSize, minVal, maxVal;

    NodeVal(int minVal, int maxVal, int maxSize)
    {
        this->maxSize = maxSize;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
};

class Solution
{
private:
    NodeVal findLargestBST(Node *root)
    {
        if (root == NULL)
            return NodeVal(INT_MAX, INT_MIN, 0);

        auto left = findLargestBST(root->left);
        auto right = findLargestBST(root->right);

        if (left.maxVal < root->data && root->data < right.minVal)
        {
            return NodeVal(min(root->data, left.minVal), max(root->data, right.maxVal), left.maxSize + right.maxSize + 1);
        }

        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        return findLargestBST(root).maxSize;
    }
};