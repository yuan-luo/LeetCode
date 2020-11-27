572. 另一个树的子树

给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

class Solution {
public:
    bool isSubtree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return isSameTree(t1, t2) || isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
    }

    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return t1->val == t2->val && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
};
