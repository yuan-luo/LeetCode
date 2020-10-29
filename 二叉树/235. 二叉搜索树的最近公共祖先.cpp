235. 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val > max(p->val, q->val)) return lowestCommonAncestor(root->left, p, q);
        if (root->val < min(p->val, q->val)) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
