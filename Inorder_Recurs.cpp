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

void inorder(struct node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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