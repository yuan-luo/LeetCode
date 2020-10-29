98. 验证二叉搜索树

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

注意：

这道题lower和upper必须是long类型。
if (root->val <= lower || root->val >= upper) 这里的判断必须是小于等于和大于等于。

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long lower, long upper) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};
