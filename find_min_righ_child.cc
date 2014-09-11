#include <iostream>

using namespace std;

struct Node
{
  Node(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
  int value;
  Node *left;
  Node *right;
};

Node* find_min_right_child(Node *root, int is_right_child)
{
  if (root == NULL)
    return NULL;

  Node *ret = find_min_right_child(root->left, 0);
  if (ret != NULL)
    return ret;

  if (is_right_child)
    return root;

  return find_min_right_child(root->right, 1);
}

int main()
{
  Node root(1);
  Node a(2);
  Node b(3);
  Node c(4);
  root.right = &a;
  a.right = &b;
  b.right = &c;
  Node *min_right_child = find_min_right_child(&root, 0);
  cout << min_right_child->value << endl;
  return 0;
}
