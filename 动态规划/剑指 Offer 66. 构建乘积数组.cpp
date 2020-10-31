剑指 Offer 66. 构建乘积数组

给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 
题解：

设计两个数组，一个记录左边的所有数字（不包括该数字）的乘积，一个记录右边的所有数字的乘积。
然后将两个乘积相乘。

class Solution {
public:
    vector<int> constructArr(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n, 1);
        vector<int> backward(n, 1);
        vector<int> ans;

        for (int i = 0; i < n - 1; ++i) {
            forward[i + 1] = nums[i] * forward[i];
        }
        for (int i = n - 1; i > 0; --i) {
            backward[i - 1] = nums[i] * backward[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            ans.push_back(forward[i] * backward[i]);
        }
        return ans;
    }
};
