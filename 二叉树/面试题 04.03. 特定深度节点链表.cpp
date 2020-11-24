面试题 04.03. 特定深度节点链表

给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

示例：

输入：[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

输出：[[1],[2,3],[4,5,7],[8]]

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* root) {
        vector<ListNode*> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            TreeNode* node;
            ListNode* head, *prev, *curr;
            for (int i = 0; i < sz; ++i) {
                node = q.front(); q.pop();
                if (i == 0) {
                    head = new ListNode(node->val);
                    prev = head;
                }
                else {
                    curr = new ListNode(node->val);
                    prev->next = curr;
                    prev = prev->next;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(head);
        }
        return ans;
    }
};
