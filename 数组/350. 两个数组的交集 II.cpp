350. 两个数组的交集 II

给定两个数组，编写一个函数来计算它们的交集。

说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; // num->appear_times
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            m[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (m.find(nums2[i]) != m.end() && m[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                --m[nums2[i]];
            }
        }
        return res;
    }
};
