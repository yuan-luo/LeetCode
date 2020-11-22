面试题 02.01. 移除重复节点

编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
 
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]

题解分析：

这道题和83题的区别是这道题的链表未排序。

我做的方法，构造三个指针pre, cur, next不断往前。
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> m;
        ListNode dummy;
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            if (m.count(cur->val)) {
                pre->next = cur->next;
                cur = cur->next;
            }
            else {
                m.insert(cur->val);
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy.next;
    }
};

题解的方法更加简洁：
https://leetcode-cn.com/problems/remove-duplicate-node-lcci/solution/cjian-ji-dai-ma-by-orangeman-9/

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> set; 
        ListNode* cur = head; 
        while(cur && cur->next){ //空节点则返回空
            set.insert(cur->val);
            if(set.count(cur->next->val)) cur->next = cur->next->next;  //找到相同元素，则删除链表
            else cur = cur->next; //开始循环
        }
        return head;
    }
};
