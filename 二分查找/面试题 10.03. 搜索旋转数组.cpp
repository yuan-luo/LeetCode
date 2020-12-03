面试题 10.03. 搜索旋转数组

搜索旋转数组。给定一个排序后的数组，包含n个整数，但这个数组已被旋转过很多次了，次数不详。
请编写代码找出数组中的某个元素，假设数组元素原先是按升序排列的。若有多个相同元素，返回索引值最小的一个。

输入
[5,5,5,1,2,3,4,5] 
5

输出
0

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (nums.empty()) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) right = mid;
                else left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                if (nums[left] <= target || target <= nums[mid]) right = mid; // 这套题这步是坑，和33题不一样。
                else left = mid + 1;
            } else {
                if (nums[left] != target) ++left;
                else right = left; // 如果相等，那么left就是答案。让left等于right，停止搜索。
            }
        }
        return nums[left] == target ? left : -1;
    }
};
