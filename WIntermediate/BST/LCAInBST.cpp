TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    //base case
    while (root!=NULL){
        if (root->data > P->data && root->data > Q->data){
           root=root->left;
        }
        else if (root->data < P->data && root->data < Q->data){
            root=root->right;
        }
        else{
            return root;
        }
    }

    

}