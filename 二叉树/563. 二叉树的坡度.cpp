563. 二叉树的坡度

给定一个二叉树，计算 整个树 的坡度 。

一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。
如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。

整个树 的坡度就是其所有节点的坡度之和。

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        postorder(root, res);
        return res;
    }
    // 返回整个树的节点值的和
    // res是整棵树的坡度
    int postorder(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int leftSum = postorder(root->left, res);
        int rightSum = postorder(root->right, res);
        res += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
};
