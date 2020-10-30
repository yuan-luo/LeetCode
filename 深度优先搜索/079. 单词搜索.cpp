79. 单词搜索

给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

题解：

这道题的关键是设计一个visited的二维数组记录某一个节点有没有被visited。
边界条件注意要考虑size()-1，因为在递进的时候要+1。否则会越界。

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
