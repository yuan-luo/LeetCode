110. 平衡二叉树

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) <= 1
            && isBalanced(root->left)
            && isBalanced(root->right)) return true;
        return false;
    }

    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};
