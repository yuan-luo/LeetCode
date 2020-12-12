324. 摆动排序 II

给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size(), j = (n + 1) / 2 - 1, k = n - 1;
        for (int i = 0; i < tmp.size(); ++i) {
            nums[i] = i & 1 ? tmp[k--] : tmp[j--];
        }
    }
};
