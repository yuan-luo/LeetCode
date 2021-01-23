513. 找树左下角的值

给定一个二叉树，在树的最后一行找到最左边的值。

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front(); q.pop();
                if (i == 0) ans = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
