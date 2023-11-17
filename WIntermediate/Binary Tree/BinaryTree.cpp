#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *builtTree(node *root)
{

    int d;
    cout << "Enter Root Value For Tree" << endl;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    root = new node(d);

    cout << "Enter Left Value For The " << d << endl;
    root->left = builtTree(root->left);

    cout << "Enter Right Value For The " << d << endl;
    root->right = builtTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main()
{

    cout << "Hi Testing" << endl;

    node *root = NULL;

    root = builtTree(root);

    // Printing the level order traversal

    levelOrderTraversal(root);

    cout << "Inorder" << endl;
    inorder(root);
    cout << "PreOrder" << endl;
    preorder(root);
    cout << "PostOrder" << endl;
    postorder(root);

    return 0;
}
// 4 1 3 -1 -1 3 2 -1 -1 2 -1 -1 -1