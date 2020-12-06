212. 单词搜索 II

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例 1：

输入：
board = 
[["o","a","a","n"],
 ["e","t","a","e"],
 ["i","h","k","r"],
 ["i","f","l","v"]], 
 
words = ["oath","pea","eat","rain"]

输出：["eat","oath"]

struct Node {
    bool word;
    string str;
    unordered_map<char, Node*> words;
};

题解：

这道题采用trie tree。学习了解一下有个思路就可以了。

class Trie {
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* p = root;
        for (char c : word) {
            if (p->words.find(c) == p->words.end()){
                Node* t = new Node();
                p->words[c] = t;
            }
        p = p->words[c];
        }
        p->str = word;
        p->word = true;
    }

    void search(vector<string>& res, vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                helper(res, board, root, i, j);
            }
        }
    }

    void helper(vector<string>& res, vector<vector<char>>& board, Node* p, int y, int x) {
        if (p->word) {
            p->word = false;
            res.push_back(p->str);
            return;
        }
        if (y < 0 || y == board.size() || x < 0 || x == board[y].size()) return;
        if (p->words.find(board[y][x]) == p->words.end()) return;
        p = p->words[board[y][x]];
        char cur = board[y][x];
        board[y][x] = '#';
        helper(res, board, p, y + 1, x);
        helper(res, board, p, y - 1, x);
        helper(res, board, p, y, x + 1);
        helper(res, board, p, y, x - 1);
        board[y][x] = cur;
    }
private:
    Node* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        vector<string> res;
        for (string& w : words) {
            trie.insert(w);
        }
        trie.search(res, board);
        return res;
    }
};

