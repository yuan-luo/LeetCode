905. 按奇偶排序数组

给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
你可以返回满足此条件的任何数组作为答案。

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = 0; j < A.size(); ++j) {
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        }
        return A;
    }
};
