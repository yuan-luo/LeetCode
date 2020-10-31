257. 二叉树的所有路径

给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

注意：

1. 要考虑过滤减枝if (root->left)

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string out;
        if (root != nullptr) helper(root, "", ans);
        return ans;
    }

    void helper(TreeNode* root, string out, vector<string>& ans) {
        out += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(out);
        }
        if (root->left) helper(root->left, out + "->", ans);
        if (root->right) helper(root->right, out + "->", ans);
    }
};
