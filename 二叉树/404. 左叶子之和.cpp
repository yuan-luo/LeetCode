404. 左叶子之和

计算给定二叉树的所有左叶子之和。

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left && !node->left->left && !node->left->right) sum += node->left->val;            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return sum;
    }
};
