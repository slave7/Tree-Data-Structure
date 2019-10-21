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

// reverse printing of level order L-R
void Reverse_level(struct node* root){
    if(!root)
        return;
    queue<node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
    	root = q.front();
    	q.pop();
    	v.push_back(root->data);
    	// for L-R right is chosen first
    	if(root->right)
    		q.push(root->right);
    	if(root->left)
    		q.push(root->left);
    }
    int n = v.size();
    for (int i = n-1; i>-1; i--)
    	cout<<v[i]<<" ";
}

int main()
{
    struct node *root = Newnode(1);
    root->left = Newnode(2);
    root->right = Newnode(3);
    root->left->left = Newnode(4);
    root->left->right = Newnode(5);
    root->right->right = Newnode(7);
    root->right->left = Newnode(6);
    Reverse_level(root);
    return 0;
}
