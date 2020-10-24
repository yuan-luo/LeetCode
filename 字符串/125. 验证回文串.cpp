
125. 验证回文串


class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1; 
        while (left < right) {
            if (sgood[left++] != sgood[right--]) return false; 
        }
        return true;
    }
};
