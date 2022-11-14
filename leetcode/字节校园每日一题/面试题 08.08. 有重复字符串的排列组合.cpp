// ###################################################### 版本1 ###################################################### //
// 去重核心：人为规定相同元素的相对顺序
class Solution {
public:
    int n;
    string temp, S;
    vector<string> ans;
    vector<int> vis;
    void dfs(int u){
        if(u == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                temp += S[i];
                vis[i] = 1;
                dfs(u + 1);
                temp.pop_back();
                vis[i] = 0;
                while(i + 1 < n && S[i] == S[i + 1]) i++;
            }
        }
    }
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        this->S = S;
        n = S.size();
        vis = vector<int>(n);
        dfs(0);
        return ans;
    }
};