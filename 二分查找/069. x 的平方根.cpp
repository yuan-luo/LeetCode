69. x 的平方根

实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

更好理解：
它说明 mid^2 <= x < (mid+1)^2，x的平方根为mid
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        if (x == 0) return 0;
        int ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else {
                if (mid + 1 > x / (mid + 1)) return mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int left = 1, right = x;
        if (x == 0) return 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
