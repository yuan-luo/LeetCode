面试题 03.04. 化栈为队

实现一个MyQueue类，该类用两个栈来实现一个队列。

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val;
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        val = st2.top();
        st2.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        int val;
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        val = st2.top();
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;
};
