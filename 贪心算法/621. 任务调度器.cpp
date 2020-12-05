621. 任务调度器

给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。其中每个字母表示一种不同种类的任务。
任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。

然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
你需要计算完成所有任务所需要的 最短时间 。

题解：

这道题目要设计一个桶。当每个桶的大小为n+1。这样相同类型的tasks必须放到不同的桶里面以保证n时间间隔。
这样规划要分两种情况，
1.当task很多的时候，如果大于桶的规划，这时候取决于task的size。
2.当task不是很多的时候，桶的个数取决于相同task数量对多的那个task的size减去1，最后要加上一个桶，大小不再是n+1，而是同拥有最大task个数的task的数量。

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (char c : tasks) {
            counts[c - 'A']++;
        }
        int maxLen = 0;
        for (int count : counts) {
            maxLen = max(maxLen, count);
        }
        int maxCount = 0;
        for (int count : counts) {
            if (count == maxLen) ++maxCount;
        }

        return max((n + 1) * (maxLen - 1) + maxCount, (int)tasks.size());
    }
};
