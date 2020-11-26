面试题 17.12. BiNode

二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

返回转换后的单向链表的头节点。

注意：本题相对原题稍作改动

示例：

输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]

解题思路：

非递归 - 利用一个前驱节点prev，记录上一个被处理的节点，当前节点被遍历到的时候，将prev.right指向当前节点node，
然后node.left置空，prev指针后移到node,最后node进入右子树即可。

递归 - 左子树递归回来之后，当前的prev指针没有发生改变，还是外部传进来的那个哨兵节点，这个时候一旦进入右子树，
之前的prev.right指针将会被重置。也就是说，root的左子树操作全部失效了。

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode dummy;
        inorder(root, &dummy);
        return dummy.right;
    }

    TreeNode* inorder(TreeNode* root, TreeNode* pre) {
        if (root != nullptr) {
            pre = inorder(root->left, pre);
            root->left = nullptr;
            pre->right = root;
            pre = root;
            pre = inorder(root->right, pre);
        }
        return pre;
    }
};
