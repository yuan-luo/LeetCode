113. 路径总和 II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。

解题思路：

注意要sum为零并且左右子节点都为空的情况下才加入答案。
out的push_back和pop_back成对出现。

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        helper(root, sum, res, out);
        return res;
    }

    void helper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& out) {
        if (root == nullptr) return;
        out.push_back(root->val);
        sum -= root->val;
        if (sum == 0 && root->left == nullptr && root->right == nullptr) res.push_back(out);
        helper(root->left, sum, res, out);
        helper(root->right, sum, res, out);
        out.pop_back();
    }
};
