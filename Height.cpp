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

// height using recursion.
int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lheight = height(node->left);  // left height
        int rheight = height(node->right);  // right height
  
        return (1+max(lheight,rheight));
    }
}

// height without using recursion
int treeHeight(node *root){ 
    // Base Case 
    if (root == NULL) 
        return 0; 
    // Create an empty queue for level order tarversal 
    queue<node *> q; 
    // Enqueue Root and initialize height 
    q.push(root); 
    int height = 0; 
  
    while (1) 
    { 
        // nodeCount (queue size) indicates number of nodes 
        // at current lelvel. 
        int nodeCount = q.size(); 
        if (nodeCount == 0) 
            return height; 
        height++; 
        // Dequeue all nodes of current level and Enqueue all 
        // nodes of next level 
        while (nodeCount > 0) 
        { 
            node *node = q.front(); 
            q.pop(); 
            if (node->left != NULL) 
                q.push(node->left); 
            if (node->right != NULL) 
                q.push(node->right); 
            nodeCount--; 
        } 
    } 
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
    cout<<height(root);
    return 0;
}
