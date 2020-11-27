面试题 04.02. 最小高度树

给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generateBST(nums, 0, nums.size() - 1);
    }

    TreeNode* generateBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = generateBST(nums, left, mid - 1);
        root->right = generateBST(nums, mid + 1, right);
        return root;
    }
};
