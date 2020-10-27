剑指 Offer 09. 用两个栈实现队列

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if (st1.empty()) return -1;
        int ans;
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        ans = st2.top();
        st2.pop();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;        
    }

    stack<int> st1;
    stack<int> st2;
};
