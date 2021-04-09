668. 乘法表中第k小的数

class Solution {
 public:
     int findKthNumber(int m, int n, int k) {
         int left = 1, right = m * n;
         while (left < right) {
             int mid = left + (right - left) / 2, cnt = 0;
             for (int i = 1; i <= m; ++i) {
                 cnt += (mid > n * i) ? n : (mid / i);
             }
             if (cnt < k) left = mid + 1;
             else right = mid;
         }
         return right;
     }
 };
