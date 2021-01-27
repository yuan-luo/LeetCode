325. 和等于 k 的最长子数组长度

给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。
如果不存在任意一个符合要求的子数组，则返回 0。

用hashmap m表示sum和index的映射关系。
如果sum=k，记录答案。
如果sum-k的和存在，说明k的和也存在。直接比较答案。

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int, int> m; // sum -> index
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) ans = i + 1;
            if (m.count(sum - k)) ans = max(ans, i - m[sum - k]);
            if (!m.count(sum)) m[sum] = i;
        }
        return ans;
    }
};
