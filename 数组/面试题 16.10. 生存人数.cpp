面试题 16.10. 生存人数

给定 N 个人的出生年份和死亡年份，第 i 个人的出生年份为 birth[i]，死亡年份为 death[i]，实现一个方法以计算生存人数最多的年份。

你可以假设所有人都出生于 1900 年至 2000 年（含 1900 和 2000 ）之间。如果一个人在某一年的任意时期处于生存状态，那么他应该被纳入那一年的统计中。
例如，生于 1908 年、死于 1909 年的人应当被列入 1908 年和 1909 年的计数。

如果有多个年份生存人数相同且均为最大值，输出其中最小的年份。

解题分析：

利用前缀树。comes是每年累计在世的人数，goes是每年走掉的人数。
这样每年最大生存人数就是comes[i] - goes[i - 1]。因为走掉的人数也算在当年生存人数中。

class Solution {
public:
    int max_num = 101;
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int len = birth.size();
        int ans = 0;
        vector<int> comes(max_num, 0);
        vector<int> goes(max_num, 0);
        for (int i = 0; i < len; ++i) {
            ++comes[birth[i] - 1900];
            ++goes[death[i] - 1900];
        } 
        for (int i = 1; i < max_num; ++i) {
            comes[i] += comes[i - 1];
            goes[i] += goes[i - 1];  
        }
        int max_live = comes[0];
        for (int i = 1; i < max_num; ++i) {
            if (comes[i] - goes[i - 1] > max_live) {
                max_live = comes[i] - goes[i - 1];
                ans = i;
            }
        }
        return 1900 + ans;
    }
};
