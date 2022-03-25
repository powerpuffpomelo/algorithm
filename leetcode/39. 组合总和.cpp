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
    void dfs(vector<int>& candidates, int target, int u, int s, vector<int>& temp){
        if(s == target){
            ans.push_back(temp);
            return;
        }
        for(int i = u; i < candidates.size(); i++){
            if(s + candidates[i] > target) break;
            temp.push_back(candidates[i]);
            dfs(candidates, target, i, s + candidates[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, temp);
        return ans;
    }
};