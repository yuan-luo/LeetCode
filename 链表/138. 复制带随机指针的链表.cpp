138. 复制带随机指针的链表

https://leetcode-cn.com/problems/copy-list-with-random-pointer/

题解：

设计一个haspmap，先把node的值存进去，然后value指向它的random node。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> m;
        Node *cur = head;
        while (cur) {
            Node *tmp = new Node(cur->val, nullptr, nullptr);
            m[cur] = tmp;
            cur = cur->next;            
            
        }
        cur = head;
        while (cur) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};

