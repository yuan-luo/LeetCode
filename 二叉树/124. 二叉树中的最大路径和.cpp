124. 二叉树中的最大路径和

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        gainSum(root, ans);
        return ans;
    }

    int gainSum(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        // 递归计算左右子节点的最大贡献值
        int left = max(0, gainSum(root->left, ans));
        int right = max(0, gainSum(root->right, ans));
        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值之和
        int sum = left + right + root->val;
        // 更新答案
        ans = max(sum, ans);
        // 返回节点的最大贡献值
        return max(left, right) + root->val;
    }
};

时间复杂度：O(N)，其中 N 是二叉树中的节点个数。对每个节点访问不超过 2 次。
空间复杂度：O(N)，其中 N 是二叉树中的节点个数。空间复杂度主要取决于递归调用层数，最大层数等于二叉树的高度，最坏情况下，二叉树的高度等于二叉树中的节点个数。

