面试题 17.10. 主要元素

数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; (i + nums.size() / 2) < nums.size(); ++i) {
            if(nums[i] == nums[i + nums.size() / 2]) return nums[i];
        }
        return -1;
    }
};
