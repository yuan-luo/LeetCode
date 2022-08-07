257. 二叉树的所有路径

给定一个二叉树，返回所有从根节点到叶子节点的路径。

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string out;
        if (root != nullptr) helper(root, "", ans);
        return ans;
    }

    void helper(TreeNode* root, string out, vector<string>& ans) {
        out += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(out);
        }
        if (root->left) helper(root->left, out + "->", ans);
        if (root->right) helper(root->right, out + "->", ans);
    }
};
