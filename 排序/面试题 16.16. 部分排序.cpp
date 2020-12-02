面试题 16.16. 部分排序

给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。
注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

思路：

只要考虑把两个边界值找出来。而且发现边界其实有规律，比如左边界一定是比它左边的值还要小，同理右边界是比它右边的值还要大。
这道题也可以考虑在一次循环中做出，只要考虑把i改成array[i] - 1 - 就可以了，但是影响可读性。写成两个循环关系不大。

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int maxValue = INT_MIN, minValue = INT_MAX;
        int first = -1, last = -1;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] < maxValue) last = i;
            maxValue = max(maxValue, array[i]);
        }
        for (int i = array.size() - 1; i >= 0; --i) {
            if (array[i] > minValue) first = i;
            minValue = min(minValue, array[i]);
        }
        return {first, last};
    }
};
