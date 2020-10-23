剑指 Offer 41. 数据流中的中位数

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

==================================================
题解:

这道题的关键是设计两个堆，一个大顶堆和一个小顶堆。大顶堆在前，小顶堆在后。

1. add数据的时候先往大顶堆里面放，再把大顶堆的top压到小顶堆里面去，
最后如果大顶堆的size小于小顶堆的size，把小顶堆的top压到大顶堆里面来。

2. 找中位数findMedian的时候再看两个堆的size大小，分别处理。

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if (lo.size() > hi.size())
            return (double) lo.top();
        else
            return (double) (lo.top() + hi.top()) * 0.5;
    }

private:
    priority_queue<int, vector<int>, less<int>> lo; // 大顶堆
    priority_queue<int, vector<int>, greater<int>> hi; //小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
