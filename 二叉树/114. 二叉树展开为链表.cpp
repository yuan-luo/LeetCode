114. 二叉树展开为链表

给定一个二叉树，原地将它展开为一个单链表。

解题思路：

先利用 DFS 的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开。
将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right != nullptr) root = root->right;
        root->right = tmp;
    }
};
