138. 复制带随机指针的链表

https://leetcode-cn.com/problems/copy-list-with-random-pointer/

题解：

设计一个hashmap，先把node的值存进去，第一轮循环下来，map里面的entry只记录value，没有next和random指针。
接下来在一轮循环，populate每个节点cur的next和random指针，它们分别就是m[cur->next]和m[cur->random]。
因为每个m[cur]其实就是相当于那个值为cur->val的节点。

/*
Definition for a Node.
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

