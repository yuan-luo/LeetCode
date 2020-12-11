面试题 03.02. 栈的最小值

请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stk.push(x);
        if (!min_stk.empty()) min_stk.push(min(min_stk.top(), x));
        else min_stk.push(x);
    }
    
    void pop() {
        int val = stk.top(); stk.pop();
        min_stk.pop();
    }
     
    int top() {
        if (stk.empty()) return -1;
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }

private:
    stack<int> stk;
    stack<int> min_stk;
};
