49. 字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

解题思路：

这道题的关键是构造一个map，然后sort str。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; // str -> ans;
        vector<vector<string>> ans;
        for (auto& iter : strs) {
            string str = iter;
            sort(str.begin(), str.end()); // 关键是sort这个str
            m[str].push_back(iter);
        }
        for (auto& iter : m) {
            ans.push_back(iter.second);
        }
        return ans;
    }
};
