15. 三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() <= 2) return ans;
        sort(nums.begin(), nums.end());
        int target = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            target = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left; --right;
                } else if (nums[left] + nums[right] < target) ++left;
                else --right;
            }
        }
        return ans;
    }
};
