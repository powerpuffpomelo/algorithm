// ###################################################### 版本1 ###################################################### //
// 按行读取，每次找到该读的位置，输出
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        int g_size = numRows * 2 - 2;
        string ans = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j + i < n; j += g_size){
                ans += s[j + i];
                if(i != 0 && i != numRows - 1 && j + g_size - i < n) ans += s[j + g_size - i];
            }
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 过一遍字符串，标记每个字符在第几行，放入对应行，最后拼接在一起
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));
        int cur_row = 0;
        bool go_down = false;
        for(char c : s){
            rows[cur_row] += c;
            if(cur_row == 0 || cur_row == numRows - 1) go_down = !go_down;
            cur_row += go_down ? 1 : -1;
        }
        string ret;
        for(string row : rows) ret += row;
        return ret;
    }
};