113. 路径总和 II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> out;
        helper(ans, out, root, sum);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& out, TreeNode* root, int sum) {
        if (root == nullptr) return;
        out.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            ans.push_back(out);
        }
        helper(ans, out, root->left, sum);
        helper(ans, out, root->right, sum);
        out.pop_back();
    } 
};
