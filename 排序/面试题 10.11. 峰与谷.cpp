面试题 10.11. 峰与谷

在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，“谷”是小于或等于相邻整数的元素。
例如，在数组{5, 8, 4, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size(), j = (n + 1) / 2 - 1, k = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) nums[i] = tmp[j--];
            else nums[i] = tmp[k--];
        }
    }
};
