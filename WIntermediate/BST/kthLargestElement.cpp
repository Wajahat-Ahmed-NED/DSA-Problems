#include<iostream>

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

void inorder(BinaryTreeNode* t, vector<int> arr){
    if(root==NULL){
        return;
    }
    inorder(t->left,arr);
    arr.push_back(t->data);
    inorder(t->right,arr);

}

BinarTreeNode* insertToBST(BinaryTreeNode* root, int data){

    if(root==NULL){
        root=new BinaryTreeNode(data);
        return root;
    }

    if(root->data>data){
        root->left=insertToBST(root->left,data);
    }
    else{
        root->right=insertToBST(root->right,data);
    }

    return root;
}

void takeInput(BinaryTreeNode* &root){
    int data;
    cin>>data;

    while(data!=-1){
        insertToBST(root,data);
        cin>>data;
    }

}

int main(){

    BinaryTreeNode root =NULL;
    
    vector<int> arr={};
    
    takeInput(root);

    inorder(root,arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    int k=3;
    cout<<arr[arr.size()-k];

    return 0;
}