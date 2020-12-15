496. 下一个更大元素 I

给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。

示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
    
写法一：推荐
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> m; // 每个数字 -> 右边第一个更大元素
        for (int n : nums) {
            while (st.size() && st.top() < n) {
                m[st.top()] = n; st.pop();
            }
            st.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};

写法二：
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size(), -1);
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> m; // value->index in ans
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // 小于
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
            m[nums2[i]] = ans[i];
        }
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = m[nums1[i]];
        }
        return res;
    }
};
