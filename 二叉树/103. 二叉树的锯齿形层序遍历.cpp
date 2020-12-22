103. 二叉树的锯齿形层序遍历

给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> out;
        if (root == nullptr) return ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while (!st1.empty() || !st2.empty()) {
            int sz = st1.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = st1.top(); st1.pop();
                out.push_back(node->val);
                if (node->left) st2.push(node->left);
                if (node->right) st2.push(node->right);
            }
            if (!out.empty()) ans.push_back(out);
            out.clear();
            sz = st2.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = st2.top(); st2.pop();
                out.push_back(node->val);
                if (node->right) st1.push(node->right);
                if (node->left) st1.push(node->left);
            }
            if (!out.empty()) ans.push_back(out);
            out.clear();
        }
        return ans;
    }
};
