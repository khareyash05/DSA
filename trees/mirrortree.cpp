
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
 
/* Helper function that allocates a new node with
the given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
                         malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
     
    return(node);
}void mirror(Node* tree){
  Node* temp;
  mirror(tree->left);
  mirror(tree->right);
  temp=tree->left;
  tree->left=tree->right;
  tree->right=temp;
}
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;
     
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
 
 
// Driver Code
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
     
    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl;
    inOrder(root);
     
    /* Convert tree to its mirror */
    mirror(root);
     
    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";
    inOrder(root);
     
    return 0;
}

void mirror(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    // Do BFS. While doing BFS, keep swapping
    // left and right children
    while (!q.empty())
    {
        // pop top node from queue
        Node* curr = q.front();
        q.pop();
 
        // swap left child with right child
        swap(curr->left, curr->right);
 
        // push left and right children
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
 