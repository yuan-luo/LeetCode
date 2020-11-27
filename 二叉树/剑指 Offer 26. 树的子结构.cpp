剑指 Offer 26. 树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:

给定的树 A:

     3
    / \
   4   5
  / \
 1   2
 
给定的树 B：

   4 
  /
 1
 
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false

示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        // 1. A树与B树完全相等
        // 2. A的左子树与B树完全相等
        // 3. A的右子树与B树完全相等
        return hasSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    // B是不是与A同root的子结构
    bool hasSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr) return true;
        if (A == nullptr) return false;
        // 1. A的根节点与B的根节点是否相同
        // 2. A的左子树与B的左子树是否相同
        // 3. A的右子树与B的右子树是否相同
        return (A->val == B->val) && hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right); 
    }
};
