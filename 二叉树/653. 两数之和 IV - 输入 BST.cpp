653. 两数之和 IV - 输入 BST

给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，
则返回 true。

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        return helper(root, k, m);
    }
    bool helper(TreeNode* node, int k, unordered_set<int>& m) {
        if (!node) return false;
        if (m.count(k - node->val)) return true;
        m.insert(node->val);
        return helper(node->left, k, m) || helper(node->right, k, m);
    }
};
