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
