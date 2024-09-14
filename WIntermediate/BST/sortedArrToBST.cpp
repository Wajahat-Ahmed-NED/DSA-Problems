#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
}

Node *
sortedArrToBalancedBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    Node *root = new Node(arr[mid]);

    root->left = sortedArrToBalancedBST(arr, start, mid - 1);
    root->right = sortedArrToBalancedBST(arr, mid + 1, end);

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *root = sortedArrToBalancedBST(arr, 0, size - 1);

    preorder(root);

    return 0;
}