// ###################################################### 版本1 ###################################################### //
// 我的版本，本题避免超时必须剪枝，根据more判断合法、根据l/r判断最小数量，而不用最终check每个字符串是否合法
class Solution {
    int n;
    set<string> ans;

    // id 当前该看第几个字母；str 当前字符串；s 完整初始字符串；more 当前左括号超过右括号的数量；l/r 还需要删除几个左括号/右括号
    void dfs(int id, string str, string& s, int more, int l, int r){
        if(more < 0 || l < 0 || r < 0) return;
        if(id == n){
            if(l == 0 && r == 0) ans.insert(str);
            return;
        }
        if(s[id] != '(' && s[id] != ')'){   // 字母
            dfs(id + 1, str + s[id], s, more, l, r);
        }else{
            if(s[id] == '('){               // 左括号，删or不删
                dfs(id + 1, str, s, more, l - 1, r);
                dfs(id + 1, str + s[id], s, more + 1, l, r);
            } 
            else if(s[id] == ')'){          // 右括号，删or不删
                dfs(id + 1, str, s, more, l, r - 1);
                dfs(id + 1, str + s[id], s, more - 1, l, r);
            } 
            
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        int l = 0, r = 0;
        for(int i = 0; s[i]; i++){
            if(s[i] == '('){
                l++;
            }else if(s[i] == ')'){
                if(l == 0) r++;
                else l--;
            }
        }
        dfs(0, "", s, 0, l, r);
        vector<string> ret;
        for(auto ss : ans) ret.push_back(ss);
        return ret;
    }
};