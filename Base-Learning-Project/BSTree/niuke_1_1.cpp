// 有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。

// 给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，
// 所有数组的顺序按照层数从上往下，且每一层的数组内元素按照从左往右排列。
// 保证结点数小于等于500。

class TreePrinter {
public:
  vector<vector<int> > printTree(TreeNode* root) {
    vector<vector<int>> result;
    vector<int> sub_result;

    queue<TreeNode*> q_tmp;

    q_tmp.push(root);

    TreeNode* last;
    TreeNode* n_last;

    last = root;

    while(!q_tmp.empty()){
      TreeNode* node = q_tmp.front();
      q_tmp.pop();

      sub_result.push_back(node->val);

      if(node->left != nullptr){
        q_tmp.push(node->left);
        n_last = node->left;
      }

      if(node->right != nullptr){
        q_tmp.push(node->right);
        n_last = node->right;
      }

      if(last == node){
        last = n_last;
        result.push_back(sub_result);
        sub_result.clear();
      }
    }
    return result;
  }
};