// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int u, int k, int n, vector<int>& temp){
        if(u > 9){
            if(k == 0 && n == 0) ans.push_back(temp);
            return;
        }
        dfs(u + 1, k, n, temp);
        temp.push_back(u);
        dfs(u + 1, k - 1, n - u, temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n, temp);
        return ans;
    }
};