111. 二叉树的最小深度

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int m = minDepth(root->left);
        int n = minDepth(root->right);
        if (root->left == nullptr) return 1 + n;
        if (root->right == nullptr) return 1 + m;
        return 1 + min(m, n);
    }
};
