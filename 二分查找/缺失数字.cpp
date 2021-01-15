题目描述

从0,1,2,...,n这n+1个数中选择n个数，组成有序数组，找出这n个数中缺失的那个数，要求O(n)尽可能小。

class Solution {
public:
    /**
     * 找缺失数字
     * @param a int整型一维数组 给定的数字串
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        // write code here
        int left = 0, right = aLen - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (a[mid] == mid) left = mid + 1;
            else if (a[mid] > mid) right = mid;
        }
        return left;
    }
};
