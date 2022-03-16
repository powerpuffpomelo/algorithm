class Solution {
public:
    vector<string> ans;
    bool check(string str){
        int a = stoi(str);
        if(a < 0 || a > 255) return false;
        if(a == 0 && str != "0") return false;
        if(str.size() > 1 && str[0] == '0') return false;
        return true;
    }
    void dfs(string &str, string temp, string cur, int i, int rem){
        if(i == str.size()) return;
        temp += str[i], cur += str[i];
        if(!check(cur)) return;
        if(i == str.size() - 1){
            if(check(cur) && rem == 0){
                ans.push_back(temp);
            }
            return;
        }
        // 后面加
        if(rem > 0 && check(cur)){
            dfs(str, temp + '.', "", i + 1, rem - 1);
        }
        // 后面不加
        dfs(str, temp, cur, i + 1, rem);
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", "", 0, 3);
        return ans;
    }
};