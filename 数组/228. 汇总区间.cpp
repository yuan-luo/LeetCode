给定一个无重复元素的有序整数数组 nums 。

返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b
 

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); ++i) {
            int pos = i;
            string str = to_string(nums[i]);
            while (i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]) ++i;
            if (pos != i) {
                str += "->" + to_string(nums[i]);
            }
            res.push_back(str);
        }
        return res;
    }
};
