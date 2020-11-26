面试题 04.12. 求和路径

给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。注意，路径不一定非得从二叉树的根节点或叶节点开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。

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

3

解释：和为 22 的路径有：[5,4,11,2], [5,8,4,5], [4,11,7]

解题思路：

注意本题条件，开始不一定是root，结尾也不一定要到叶子节点。
所以要考虑root是left和right的递归调用。

class Solution {
public:
    int ans = 0;
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        helper(root, 0, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return ans;
    }

    void helper(TreeNode* root, int cur_sum, int sum) {
        if (root == nullptr) return;
        cur_sum += root->val;
        if (cur_sum == sum) ++ans;
        helper(root->left, cur_sum, sum);
        helper(root->right, cur_sum, sum);
    }
};
