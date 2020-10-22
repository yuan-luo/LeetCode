703. 数据流中的第K大元素

设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
说明:
你可以假设 nums 的长度≥ k-1 且k ≥ 1。

题解：
使用一个小顶堆，每次把一个数push到这个堆里面来。当堆的size大于k的时候pop一个顶堆出去。
*** 这样的话，小于这个堆的数就永远进不来，因为每次刚加进来就会是堆顶，然后马上就会被弹出去。

经过若干轮以后，这个小顶堆就记录了这个数据流中最大的K个数。而top这个数最小，所以就是整个数据流中的第K大数。

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto n : nums) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        K = k;
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > K) q.pop();
        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q; // 小顶堆
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

