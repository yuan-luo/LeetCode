337. 打家劫舍 III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
    vector<int> dfs(TreeNode *root) {
        vector<int> ans(2, 0); // ans[0]不包括自己，ans[1]包括自己
        if (root == nullptr) return ans;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        // 左边包括left或不包括left的最大值 加上 右边包括right或不包括right的最大值
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // root本身加上左边不包括left加上右边不包括right
        ans[1] = root->val + left[0] + right[0];
        return ans;
    }
};
