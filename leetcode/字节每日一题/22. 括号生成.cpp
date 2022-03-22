// ###################################################### 版本2 ###################################################### //
// dfs，非常简洁优雅
class Solution {
public:
    vector<string> ans;

    void dfs(int n, int lc, int rc, string str){
        if(lc == n && rc == n) ans.push_back(str);
        else{
            if(lc < n) dfs(n, lc + 1, rc, str + '(');
            if(lc > rc) dfs(n, lc, rc + 1, str + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
// dfs
class Solution {
public:
    vector<string> ans;
    string temp;
    void dfs(string temp, int u, int n){  // u表示，左括号比右括号多的数量
        if(temp.size() == n * 2){
            if(u == 0) ans.push_back(temp);
            return;
        }
        if(u > 0){
            dfs(temp + ')', u - 1, n);
        }
        dfs(temp + '(', u + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        dfs(temp, 0, n);
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