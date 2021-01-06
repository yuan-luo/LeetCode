25. K 个一组翻转链表

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：

给你这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5
    
推荐解法：

/*
-1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |    | 
pre  cur  nex  tmp

-1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |    | 
pre       cur  nex  tmp

-1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    | 
pre            cur  nex  tmp
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        int num = 0;
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode *cur = &dummy, *nex, *tmp, *pre = &dummy;
        while (cur = cur->next) ++num;
        while (num >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; ++i) {
                tmp = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            pre = cur;
            num -= k;
        }
        return dummy.next;
     }
};
    
解法二：

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // D->1->2->3->[4->5->6]->7
        // =>
        // D->[3->2->1]->[6->5->4]->7

        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        while (prev != nullptr) {
            prev = reverseNextKGroup(prev, k);
        }

        return dummy.next;
    }

    // head->n1->n2->...->nk->nk+1
    // =>
    // head->nk->nk-1->...->n1->nk+1
    ListNode* reverseNextKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* n1 = head->next;
        for (int i = 0; i < k; ++i) {
            curr = curr->next;
            if (curr == nullptr) return nullptr;
        }
        ListNode* nk = curr;
        ListNode* nkplus = curr->next;
        ListNode* prev = head;
        curr = head->next;
        while (curr != nkplus) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // head->n1 nk->nk-1->...->n1<->head
        head->next = nk;
        n1->next = nkplus;
        return n1;
    }
};
