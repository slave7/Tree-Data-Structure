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

// height of tree
int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        return (1+max(lheight,rheight));
    }
}

void printGivenLevel(node* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

void printLevelOrder(node* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}

// Level order ITERATIVE
void LevelOrder(struct node *root) 
{ 
    // empty tree
    if (root == NULL)  return; 
  
    queue<node *> q; 
  
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // can also do directly with root instead of creating node
        node *node = q.front(); 
        cout << node->data << " "; 
        q.pop();
  
        if (node->left != NULL) 
            q.push(node->left); 
  
        if (node->right != NULL) 
            q.push(node->right); 
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
    printLevelOrder(root);
    return 0;
}
