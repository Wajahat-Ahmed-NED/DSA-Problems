// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


Node* insertIntoBST(Node* root,int d){
    //basecase
    if (root==NULL){
        root=new Node(d);
        return root;
    }
    
    if (d > root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
    
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertIntoBST(root,data);
        cin>>data;
}
}


Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
 
Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}   

Node* deleteFromBST(Node* root, int val){
    if(root==NULL){
        return root;
    }
    if (root->data==val){
        // for 0 child
        if (root->left ==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        // for 1 left child
        if (root->left != NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        
        
        // for 1 right child
        if (root->left ==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        
        // for 2 childs
        if(root->left != NULL && root->right !=NULL){
            int mini = minVal(root->right)->data;
            root->data=mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    
    else if (root->data >val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main() {
    // Write C++ code here
    cout << "Hello world!"<<endl;
    
    Node* root= NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Min Val is "<<minVal(root)->data<<endl;
    cout<<"Max Val is "<<maxVal(root)->data<<endl;
    
    cout<<deleteFromBST(root,30)<<endl;
    return 0;
}