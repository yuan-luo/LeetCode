23. 合并K个升序链表

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

题解：

这道题的关键是引入一个大小为K的小根堆。
（凡是遇到K字眼的题目第一时间想到构造大小根堆）

复杂（不太熟悉）的第一个地方是构造一个priority_queue的operator()。
注意小根堆的回调函数是>。

另外一个巧妙之处是构造while的逻辑结构：
当queue不为空的时候:
1. 取出top元素，
2. 把top元素所在的链表的下一个节点插入queue中，
3. 指针往后走继续循环

class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            if (a->val > b->val) return true;
            return false;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (auto item : lists) {
            if (item) q.push(item);
        }
        ListNode dummy;
        ListNode *cur = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top(); q.pop();
            if (node->next) q.push(node->next);
            cur->next = node;
            cur = cur->next;
        }
        return dummy.next;
    }
};
