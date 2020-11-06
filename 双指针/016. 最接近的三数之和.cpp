16. 最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closet = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int diff = abs(target - closet);
        
        for (int k = 0; k < nums.size() - 2; k++) {
            int left = k + 1; right = nums.size()-1;
            while (left < right) {
                int sum = nums[k] + nums[left] + nums[right];
                if (abs(target - sum) < diff) {
                    diff = abs(target - sum);
                    closet = sum;
                } 
                if (sum < target) left++; 
                else right--;
            }

        }
        return closet;
    }
};
