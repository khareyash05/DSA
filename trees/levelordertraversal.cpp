#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};
void printLevelOrder(Node *root)
{
  if(root==NULL) cout << "NULL";
  queue<Node*>q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    Node* node = q.front();
    q.pop();
    if(node!=NULL){
      cout<<node->data;
      if(node->left) q.push(node->left);
      if(node->right)q.push(node->right);
    }
    else if(!q.empty()) q.push(NULL);
  }
}
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main() {
  Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}