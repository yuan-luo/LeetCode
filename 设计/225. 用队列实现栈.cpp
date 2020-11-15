225. 用队列实现栈

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
 
说明：

你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

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
