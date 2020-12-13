687. 最长同值路径

给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:
输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:
2

思路:

注意这道题和124题 二叉树中的最大路径和 类似。都是选择左子树和右子树的gain做比较。
  
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    int helper(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        int pl = 0;
        int pr = 0;
        if (root->left != nullptr && root->val == root->left->val) pl = left + 1;
        if (root->right != nullptr && root->val == root->right->val) pr = right + 1;
        ans = max(ans, pl + pr);
        return max(pl, pr);
    }
};
