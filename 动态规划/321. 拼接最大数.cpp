321. 拼接最大数

给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        for (int k1 = 0; k1 <= k; ++k1) {
            const int k2 = k - k1;
            if (k1 > n1 || k2 > n2) continue;
            ans = max(ans, mergeNumber(maxNumber(nums1, k1),
                                     maxNumber(nums2, k2)));
        }
        return ans;        
    }
    
private:
    vector<int> maxNumber(const vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<int> ans;
        int to_pop = nums.size() - k;
        for (const int num : nums) {
            while (!ans.empty() && num > ans.back() && to_pop > 0) {
                --to_pop;
                ans.pop_back();
            }
            ans.push_back(num);
        }
        ans.resize(k);
        return ans;
    }

    vector<int> mergeNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans;
        vector<int> v1 = nums1;
        vector<int> v2 = nums2;
        while (v1.size() + v2.size()) {
            vector<int> &tmp = v1 > v2 ? v1 : v2;
            ans.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return ans;
    }
};
