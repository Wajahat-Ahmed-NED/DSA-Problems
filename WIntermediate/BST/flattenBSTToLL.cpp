#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root,vector<int> &arr){
    if (root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> arr;
    inorder(root,arr);
    int n=arr.size();

    TreeNode<int>* newRoot = new TreeNode<int>(arr[0]);
    TreeNode<int>* curr=newRoot;

    for (int i=1; i<n;i++){
        TreeNode<int>* temp = new TreeNode<int>(arr[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;

    return newRoot;

}
