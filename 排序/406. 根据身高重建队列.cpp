406. 根据身高重建队列

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对 (h, k) 表示，其中 h 是这个人的身高，
k 是应该排在这个人前面且身高大于或等于 h 的人数。 

例如：[5,2] 表示前面应该有 2 个身高大于等于 5 的人，而 [5,0] 表示前面不应该存在身高大于等于 5 的人。

编写一个算法，根据每个人的身高 h 重建这个队列，使之满足每个整数对 (h, k) 中对人数 k 的要求。

示例：

输入：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
输出：[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

解题思路：

这道题先把原数组排序，按照先H高度降序，K个数升序排序，
然后把排好序的数组按照插入到一个新的数组，根据K插入到K的位置上。

假设候选队列为 A，已经站好队的队列为 B.
从 A 里挑身高最高的人 x 出来，插入到 B. 因为 B 中每个人的身高都比 x 要高，因此 x 插入的位置，
就是看 x 前面应该有多少人就行了。比如 x 前面有 5 个人，那 x 就插入到队列 B 的第 5 个位置。

Sort过程：
[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
Insert过程：
[7,0]
[7,0], [7,1]
[7,0], [6,1], [7,1]
[5,0], [7,0], [6,1], [7,1]
[5,0], [7,0], [5,2], [6,1], [7,1]
[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int> b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> ans;
        for (auto& e : people) {
            ans.insert(ans.begin() + e[1], e);
        }
        return ans;
    }
}; 
