315. 计算右侧小于当前元素的个数

https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/

给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例：

输入：nums = [5,2,6,1]
输出：[2,1,1,0] 
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素

解题思路：

从右到左二分查找插入排序。
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp, ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = tmp.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tmp[mid] >= nums[i]) right = mid;
                else left = mid + 1;                
            }
            ans[i] = right; 
            tmp.insert(tmp.begin() + right, nums[i]);
        }
        return ans;
    }
};
