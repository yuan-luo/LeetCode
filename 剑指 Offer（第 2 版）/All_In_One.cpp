剑指 Offer 03. 数组中重复的数字

找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (i != nums[i]) {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }
};

剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0, len = s.size();
        for (auto c : s) {
            if (c == ' ') ++cnt;
        }
        s.resize(len + cnt * 2);
        for (int i = len - 1, j = s.size() - 1; i < j; --i, --j) {
            if (s[i] != ' ') s[j] = s[i]; 
            else {
                s[j - 2] = '%'; s[j - 1] = '2'; s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};

剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stack;
        vector<int> res;
        ListNode *curr = head;
        while (curr) {
            stack.emplace(curr->val);
            curr = curr->next;
        }
        while (!stack.empty()) {
            res.emplace_back(stack.top());
            stack.pop();
        }
        return res;
    }
};

剑指 Offer 11. 旋转数组的最小数字

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) return 0;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right = right - 1;
            }
        }
        return numbers[left];
    }
};

剑指 Offer 12. 矩阵中的路径

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (helper(board, visited, word, 0, i, j))
                    return true;
            }
        
        return false;
    }

    bool helper(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int index, int y, int x) {
        if (index == word.size()) return true;

        if (y < 0 || x < 0 || y > board.size() - 1 || x > board[0].size() - 1) return false;
        if (visited[y][x]) return false;
        if (board[y][x] != word[index]) return false;
        visited[y][x] = 1;
        bool res = helper(board, visited, word, index + 1, y - 1, x) ||
                   helper(board, visited, word, index + 1, y + 1, x) ||
                   helper(board, visited, word, index + 1, y, x - 1) ||
                   helper(board, visited, word, index + 1, y, x + 1);
        visited[y][x] = 0;
        return res;
    }
};

剑指 Offer 13. 机器人的运动范围

class Solution {
public:
    int digit_sum(int i) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfsSolver(0, 0, m, n, k, visited);
    }

    int dfsSolver(int i, int j, int m, int n, int k, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n
            || (digit_sum(i) + digit_sum(j)) > k
            || visited[i][j] == true) {
                return 0;
            }
        visited[i][j] = true;
        return 1 + dfsSolver(i + 1, j, m, n, k, visited)
                 + dfsSolver(i - 1, j, m, n, k, visited)
                 + dfsSolver(i, j + 1, m, n, k, visited)
                 + dfsSolver(i, j - 1, m, n, k, visited);
    }
};
