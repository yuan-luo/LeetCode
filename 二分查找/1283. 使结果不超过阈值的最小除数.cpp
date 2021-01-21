1283. 使结果不超过阈值的最小除数

给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，
然后将数组里每个数都除以它，并对除法结果求和。

请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。

题目保证一定有解。

就是暴力穷举，暴力穷举过程中，因子逐渐自增。
实际上，我们可以通过分析得到因子的上确界
（大于这个值的所有因子，都将使得nums中的每一个值经过除法之后都为1），
这样我们可以通过二分法，更快找到目标因子。

class Solution {
private:
    int sum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (auto n : nums) {
            sum += n / divisor + (n % divisor == 0 ? 0 : 1);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = nums[nums.size() - 1]; //max nums
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int n = sum(nums, mid);
            if (n > threshold) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
