请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]

题解：

设计一个queue和一个deque。
deque永远记录当前queue中的最大数。

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (dq.empty()) return -1;
        else return dq.front();
    }
    
    void push_back(int value) {
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        dq.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (dq.empty()) return -1;
        int top = q.front();

        if (dq.front() == top) {
            dq.pop_front();
        }
        q.pop();
        return top;
    }

private:
    queue<int> q;
    deque<int> dq;

};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
