366. Find Leaves of Binary Tree 找二叉树的叶节点

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \
      4   5    

Output: [[4,5,3],[2],[1]]
 

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          
 
2. Now removing the leaf [2] would result in this tree:

          1          
 
3. Now removing the leaf [1] would result in the empty tree:

          []         

解题思路：

思路是这样的，每一个节点从左子节点和右子节点分开走可以得到两个深度，由于成为叶节点的条件是左右子节点都为空，
所以我们取左右子节点中较大值加1为当前节点的深度值，知道了深度值就可以将节点值加入到结果res中的正确位置了，
求深度的方法我们可以参见 Maximum Depth of Binary Tree 中求最大深度的方法，参见代码如下：

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return -1;
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));
        if (depth >= res.size()) res.resize(depth + 1);
        res[depth].push_back(root->val);
        return depth;
    }
};
