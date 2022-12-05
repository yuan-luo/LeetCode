109. 有序链表转换二叉搜索树
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:
给定的有序链表： [-10, -3, 0, 5, 9],
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        pre->next = nullptr;
        TreeNode* root = new TreeNode(slow->val);
        if (head != slow) root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }
};
