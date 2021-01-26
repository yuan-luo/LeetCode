71. 简化路径

以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string ans;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i;
            if (i == path.size()) break;
            int start = i, end = 0;
            while (i < path.size() && path[i] != '/') {
                ++i;
            }
            end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()) v.pop_back();
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        for (int i = 0; i < v.size(); ++i) {
            ans += '/' + v[i];
        }
        return ans;
    }
};
