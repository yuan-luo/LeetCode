面试题 02.04. 分割链表

编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。
分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

示例:

输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8

题目要求是只要把小于x的数移动到所有x的左方就行,没有顺序要求，而且等于x,大于x这些元素没有要求！

所以运用双指针,第一个指针落在不小于x的节点上,第二个向前移动。如果第二个指针遇到小于x的节点,交换二者的值,然后第一个指针指向next。
第二个指针肯定走得更快,所以第一个指针一直处于不小于x的节点的位置，或者就是两个指针重叠,这时候还是礼貌性地交换一下罢了。

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *pre = head, *cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                int tmp = cur->val;
                cur->val = pre->val;
                pre->val = tmp;
                pre = pre->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
