struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

preorderTraversal(TreeNode *root) {
    vector<int> result;
    if(root==NULL) {
      return 0;
    } else {
        list<TreeNode*> l;
        TreeNode* tmp;
        l.push_back(root);
        while(!l.empty()) { 
	    tmp=l.front();
	    l.pop_front();
	    result.push_back(tmp->val);
	    if(tmp->right!=NULL)
	    {
	      l.push_front(tmp->right);
	    }
	  if(tmp->left!=NULL)
	    {
	      l.push_front(tmp->left);
	        
	    }
	   
	}
       
    }
  return result;
        
}
