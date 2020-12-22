475. 供暖器

冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
在加热器的加热半径范围内的每个房屋都可以获得供暖。
现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
说明：所有供暖器都遵循你的半径标准，加热的半径也一样。

思路：

先将heaters排序。再依次处理每位house，利用二分查找找到每个house的右边第一个heater和左边第一个heater。
然后每轮循环记录当前最大的heater半径。

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (auto house : houses) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) left = mid + 1;
                else right = mid;
            }
            int inst1 = (right == n) ? INT_MAX : heaters[right] - house;
            int inst2 = (right == 0) ? INT_MAX : house - heaters[right - 1];
            ans = max(ans, min(inst1, inst2));
        }
        return ans;
    }
};
