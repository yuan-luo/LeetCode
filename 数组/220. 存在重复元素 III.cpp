220. 存在重复元素 III

https://leetcode-cn.com/problems/contains-duplicate-iii/

在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。

如果存在则返回 true，不存在返回 false。

题解：

这里我们使用map数据结构来解,用来记录数字和其下标之间的映射。
这里需要两个指针i和j，刚开始i和j都指向0，然后i开始向右走遍历数组，如果i和j之差大于k，且m中有nums[j]，则删除并j加一。
这样保证了m中所有的数的下标之差都不大于k。
然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的范围，所有小于这个阈值的数和nums[i]的差的绝对值会大于t。
然后检测后面的所有的数字，如果最小的数和nums[i]的差的绝对值小于等于t，则返回true。最后遍历完整个数组返回false。代码如下：

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m; // value -> index
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
