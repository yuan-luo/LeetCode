225. 用队列实现栈

使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

题解思路：

这道题的关键是在pop的时候要把queue前面n - 1个数字依次弹出并加到queue队尾去。
这样在queue首的就是最加入的数字。
比如：
1 2 3 4 5 要pop出5，那么把1，2，3，4依次插入队尾。
5 1 2 3 4 然后把5再pop出去。
要得到top的算法也是类似。

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for (int i = 0; i < q.size() - 1; ++i) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        for (int i = 0; i < q.size() - 1; ++i) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int ans = q.front();
        q.pop();
        q.push(ans);
        return ans;        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }

private:
    queue<int> q;
};
