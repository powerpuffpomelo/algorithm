// ###################################################### 版本 ###################################################### //
// 位运算，01代表选或不选   O(2^n * n)
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < (1 << n); i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if(i >> j & 1) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// dfs
class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int>& nums, int u, vector<int>& temp){
        if(u == nums.size()){
            ans.push_back(temp);
            return;
        }
        dfs(nums, u + 1, temp);
        temp.push_back(nums[u]);
        dfs(nums, u + 1, temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(nums, 0, temp);
        return ans;
    }
};