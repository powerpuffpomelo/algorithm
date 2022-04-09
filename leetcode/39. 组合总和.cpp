// ###################################################### 版本2 ###################################################### //
// dfs
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(vector<int>& c, int target, int u){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(u == c.size()) return;
        for(int i = 0; i * c[u] <= target; i++){
            dfs(c, target - i * c[u], u + 1);
            temp.push_back(c[u]);
        }
        for(int i = 0; i * c[u] <= target; i++){
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dfs(c, target, 0);
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// dfs
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int n;
    void dfs(vector<int>& candidates, int target, int st, vector<int>& temp){
        if(target <= 0){
            if(target == 0) ans.push_back(temp);
            return;
        }
        for(int i = st; i < n; i++){
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        dfs(candidates, target, 0, temp);
        return ans;
    }
};