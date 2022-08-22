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