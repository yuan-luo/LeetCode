543. 二叉树的直径.cpp

给定一棵二叉树，你需要计算它的直径长度。
一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

思路：

直径其实就是左子树深度加上右子树深度。

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDepth(root, res);
        return res;
    }
    int maxDepth(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};
