124. 二叉树中的最大路径和

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = INT_MIN;
        gainSum(root, ans);
        return ans;
    }

    int gainSum(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int l = max(0, gainSum(root->left, ans));
        int r = max(0, gainSum(root->right, ans));
        int sum = l + r + root->val;
        ans = max(sum, ans);
        return max(l, r) + root->val;
    }
};
