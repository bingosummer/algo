#include <iostream>
#include <climits>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

int helper(TreeNode *root) {
  int min = INT_MAX;
  int max = INT_MIN;

  if (root == NULL)
    return 0;
          
  stack<TreeNode *> s = stack<TreeNode *>();
  s.push(root);
      
  while (!s.empty()) {
    TreeNode *current = s.top();
    s.pop();
    if (current->val < min) min = current->val;
    if (current->val > max) max = current->val;
    if (current->right != NULL)
	s.push(current->right);
    if (current->left != NULL)
	s.push(current->left);
  }
      
  return max - min;
}

int main()
{
  TreeNode root(0);
  TreeNode n2(2);
  TreeNode n4(4);
  TreeNode n6(6);
  TreeNode n8(8);
  TreeNode n10(10);
  root.left = &n2;
  root.right = &n4;
  n2.left = &n6;
  n4.right = &n8;
  n8.left = &n10;

  cout << helper(&root) << endl;

  return 0;
}
