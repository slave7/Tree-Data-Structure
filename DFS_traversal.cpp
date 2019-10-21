#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
// new node insertion
struct node* Newnode(int data){
    struct node* temp = new node;
    temp->data = data;
    temp->left=temp->right = NULL;
    return temp;
};


// preorder traversal
void preorder(struct node* root){
    if(!root)
        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(struct node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


// postorder traversal
void postorder(struct node* root){
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct node *root = Newnode(13);
    root->left = Newnode(12);
    root->right = Newnode(10);
    root->left->left = Newnode(4);
    root->left->right = Newnode(19);
    root->right->right = Newnode(9);
    root->right->left = Newnode(16);
    inorder(root);
    return 0;
}
