// ###################################################### 版本2 ###################################################### //
// dfs，非常简洁优雅
class Solution {
public:
    vector<string> ans;

    void dfs(int n, int lc, int rc, string str){
        if(lc == n && rc == n) ans.push_back(str);
        else{
            if(lc < n) dfs(n, lc + 1, rc, str + '(');
            if(rc < n && lc > rc) dfs(n, lc, rc + 1, str + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// dfs
class Solution {
public:
    int len;
    vector<string> ans;
    void dfs(string &str, stack<char> &stk, int k){
        if(str.size() == len){
            ans.push_back(str);
            return;
        }
        if(k){
            stk.push('(');
            str += '(';
            dfs(str, stk, k - 1);
            stk.pop();
            str.pop_back();
        }
        if(stk.size()){
            str += ')';
            stk.pop();
            dfs(str, stk, k);
            stk.push('(');
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        len = n * 2;
        string str;
        stack<char> stk;
        dfs(str, stk, n);
        return ans;
    }
};