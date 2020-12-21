1123. 最深叶节点的最近公共祖先

给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。

回想一下：

叶节点 是二叉树中没有子节点的节点
树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
 
注意：本题与力扣 865 重复：https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes/

思路：

设置一个全局lca和全局deepest深度值。然后在函数中每一层记录深度，如果一个节点的左右子树的深度都为deepest，那么lca就是当前节点。

class Solution {
public:
    int deepest;
    TreeNode* lca;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root, 0);
        return lca;
    }
    int helper(TreeNode* node, int depth) {
        deepest = max(deepest, depth);
        if (node == nullptr) return depth;
        int left = helper(node->left, depth + 1);
        int right = helper(node->right, depth + 1);
        if (left == deepest && right == deepest) lca = node;
        return max(left, right);
    }
};
