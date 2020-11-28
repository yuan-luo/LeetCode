面试题 08.04. 幂集

幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> out;

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ans;
    }

    void helper(vector<int>& nums, int level) {
        ans.push_back(out);
        for (int i = level; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            helper(nums, i + 1);
            out.pop_back();
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) continue;
        }
    }
};
