// ###################################################### 版本2 ###################################################### //
// 预处理，优化时间复杂度
class Solution {
public:
    vector<vector<bool>> f;  // 预处理，f[i][j]代表从i到j是否是回文串
    vector<string> temp;
    vector<vector<string>> ans;
    
    void dfs(string& s, int u){
        if(u == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = u; i < s.size(); i++){
            if(f[u][i]){
                temp.push_back(s.substr(u, i - u + 1));
                dfs(s, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        f = vector<vector<bool>>(n, vector<bool>(n));
        for(int j = 0; j < n; j++){
            for(int i = 0; i <= j; i++){
                if(i == j) f[i][j] = true;
                else if(s[i] == s[j]){
                    if(i + 1 == j || f[i + 1][j - 1]) f[i][j] = true;
                }
            }
        }
        dfs(s, 0);
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    bool check(string& a){
        for(int i = 0, j = a.size() - 1; i < j; i++, j--){
            if(a[i] != a[j]) return false;
        }
        return true;
    }
    void dfs(string& s, int u){
        if(u == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = u; i < s.size(); i++){
            string a = s.substr(u, i - u + 1);
            if(check(a)){
                temp.push_back(a);
                dfs(s, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};