155. 最小栈

设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

题解：

这道题的关键之处在与，当push进去的数大于mst.top()的时候，把mst.top()再push进去一次！
使得mst的size和st永远保持一致，并且mst的top看下来永远记录当前st中的最小的value。

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        mst.push(INT_MAX);
    }
    
    void push(int x) {
        if (x < mst.top()) {
            mst.push(x);
        } else {
            mst.push(mst.top()); // 关键！！
        }
        st.push(x);
    }
    
    void pop() {
        mst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
    
private:
    stack<int> st;
    stack<int> mst;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
