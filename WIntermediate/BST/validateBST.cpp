//My Approach

  if (root==NULL){
        return true;
    }
    if (root->left != NULL && root->right != NULL){
        if (root->data >= root->left->data && root->data <= root->right->data){
            bool left=isBST(root->left);
            bool right=isBST(root->right);
            return left && right;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
   
    // if (root->data >= min && root->data <= max){
    //     bool left=isBST(root->left, min,  root->data);
    //     bool right=isBST(root->right, root->data,max);
    //     return left && right;
    // }

//--------------Actual Approach-----------
#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isBST(BinaryTreeNode<int> *root,int min,int max){
    if (root==NULL){
        return true;
    }
    if (root->data >= min && root->data <= max){
        bool left=isBST(root->left, min,  root->data);
        bool right=isBST(root->right, root->data,max);
        return left && right;
    }
    return false;

}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);
}