662. 二叉树最大宽度

https://leetcode-cn.com/problems/maximum-width-of-binary-tree/

这道题目的关键是设计出一个pair<TreeNode*, unsigned long long>类型的queue。
pair的value是position。

然后注意到下层的左右节点的位置分别是上层的2*pos和2*pos+1。

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            ans = max(ans, int(q.back().second - q.front().second + 1));
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front().first;
                unsigned long long pos = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, 2 * pos});
                if (node->right) q.push({node->right, 2 * pos + 1});
            }
        }
        return ans;
    }
};
