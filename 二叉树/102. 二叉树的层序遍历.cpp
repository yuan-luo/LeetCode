102. 二叉树的层序遍历

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 
（即逐层地，从左到右访问所有节点）。

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return res;        
        q.push(root);
        
        while (!q.empty()) {
            vector<int> oneLevel;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front();
                q.pop();
                oneLevel.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(oneLevel);
        }
        return res;
    }
};
