#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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
***************/

void inorder(BinaryTreeNode<int>* root,vector<int> &arr){
    if (root==NULL){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here

    vector<int> inputVal;

    inorder(root, inputVal);

    int i=0;
    int j=inputVal.size()-1;

    while( i < j){
        int sum=inputVal[i]+inputVal[j];
        if (target==sum){
            return true;
        }
        else if (sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}