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

// height
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


// no of nodes between longest path
// O(n^2)
int width(struct node* root){
    if(!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);

    int lw = width(root->left);
    int rw = width(root->right);

    return max(1+lh+rh, max(lw,rw));
}

// O(n)
int diameterOpt(struct node *root, int* height) 
{ 
  /* lh --> Height of left subtree 
     rh --> Height of right subtree */
  int lh = 0, rh = 0; 
   
  /* ldiameter  --> diameter of left subtree 
     rdiameter  --> Diameter of right subtree */
  int ldiameter = 0, rdiameter = 0; 
   
  if(root == NULL) 
  { 
    *height = 0; 
     return 0; /* diameter is also 0 */
  } 
   
  /* Get the heights of left and right subtrees in lh and rh 
    And store the returned values in ldiameter and ldiameter */
  ldiameter = diameterOpt(root->left, &lh); 
  rdiameter = diameterOpt(root->right, &rh); 
   
  /* Height of current node is max of heights of left and 
     right subtrees plus 1*/
  *height = max(lh, rh) + 1; 
   
  return max(lh + rh + 1, max(ldiameter, rdiameter)); 
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
    cout<<width(root)<<endl;
    int ptr = 0;
    cout<<diameterOpt(root,&ptr);
    return 0;
}