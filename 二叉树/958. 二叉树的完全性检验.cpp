958. 二叉树的完全性检验

给定一个二叉树，确定它是否是一个完全二叉树。

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool found = false; // found nullptr节点
        while (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if (node == nullptr) found = true;
            else {
                if (found) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};
