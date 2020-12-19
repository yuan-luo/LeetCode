1026. 节点与其祖先之间的最大差值

给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

题解：

把整个path的最大值和最小值一路传下去，ans就是mx - mn值。

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* root, int mx, int mn) {
        if (root == nullptr) return mx - mn;
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        return max(dfs(root->left, mx, mn), dfs(root->right, mx, mn));
    }
};
