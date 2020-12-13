75. 颜色分类

https://leetcode-cn.com/problems/sort-colors/

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]

=====================================================
题解一：

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; ++i) {
            while (nums[i] == 2 && i < p2) {
                swap(nums[i], nums[p2]);
                --p2;
            }            
            while (nums[i] == 0 && i > p0) { 
                swap(nums[i], nums[p0]);
                ++p0;
            } 
        }
    }
};

题解二：

犯过错误
1. 把i的下界设成nums.size()，这里应该设置为r。因为r后面的数字全部是2了。
        for (int i = 0; i < nums.size(); ++i) {
2. 处理2的时候没有把i--，因为当遇到nums[i]==2的时候要退格，否则i再下一轮循环往前走就没机会处理这个和2交换后的值了，而它有可能是0。

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1;
        for (int i = 0; i <= p2; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++; 
            }
            if (nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--; --i;
            }
        }
    }
};
