// ###################################################### 版本1 ###################################################### //
// 我的初版 dfs
class Solution {
public:
    int n;
    vector<string> ans;
    set<string> se;
    string cat_string(vector<string> temp){
        string ret;
        for(auto s : temp) ret += s + ' ';
        ret.pop_back();
        return ret;
    }
    void dfs(int i, vector<string>& temp, string& s){
        if(i == n){
            ans.push_back(cat_string(temp));
        }
        for(int j = i + 1; j <= n; j++){
            string sub = s.substr(i, j - i);
            if(se.count(sub)){
                temp.push_back(sub);
                dfs(j, temp, s);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto word : wordDict) se.insert(word);
        vector<string> temp;
        dfs(0, temp, s);
        return ans;
    }
};