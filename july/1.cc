// Convert a binary search tree into a double linked list

#include <iostream>

using namespace std;

struct BSTreeNode
{
  int m_nValue;
  BSTreeNode *m_pLeft;
  BSTreeNode *m_pRight;
};

void helper(BSTreeNode *&head, BSTreeNode *&tail, BSTreeNode *root)
{
  BSTreeNode *lt, *rh;
  if (root == NULL) {
    head = NULL;
    tail = NULL;
    return;
  }
  helper(head, lt, root->m_pLeft);
  helper(rh, tail, root->m_pRight);
  if (lt != NULL) {
    lt -> m_pRight = root;
    root -> m_pLeft = lt;
  } else {
    head = root;
  }
  if (rh != NULL) {
    root -> m_pRight = rh;
    rh -> m_pLeft = root;
  } else {
    tail = root;
  }
}

BSTreeNode *treeToLinkedList(BSTreeNode *root)
{
  BSTreeNode *head, *tail;
  helper(head, tail, root);
  return head;
}

int main()
{
  BSTreeNode *root;
  BSTreeNode *n4 = new BSTreeNode();
  BSTreeNode *n6 = new BSTreeNode();
  BSTreeNode *n8 = new BSTreeNode();
  BSTreeNode *n10 = new BSTreeNode();
  BSTreeNode *n12 = new BSTreeNode();
  BSTreeNode *n14 = new BSTreeNode();
  BSTreeNode *n16 = new BSTreeNode();
  n4 -> m_nValue = 4;
  n6 -> m_nValue = 6;
  n8 -> m_nValue = 8;
  n10 -> m_nValue = 10;
  n12 -> m_nValue = 12;
  n14 -> m_nValue = 14;
  n16 -> m_nValue = 16;
  n10 -> m_pLeft = n6;
  n10 -> m_pRight = n14;
  n6 -> m_pLeft = n4;
  n6 -> m_pRight = n8;
  n14 -> m_pLeft = n12;
  n14 -> m_pRight = n16;
  root = n10;

  BSTreeNode *head = treeToLinkedList(root);
  BSTreeNode *tail;
  while (head) {
    cout << head -> m_nValue << " ";
    tail = head;
    head = head -> m_pRight;
  }
  cout << endl;
  while (tail) {
    cout << tail -> m_nValue << " ";
    tail = tail -> m_pLeft;
  }
  cout << endl;
  return 0;
}
