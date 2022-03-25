class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;
    vector<int> temp;
    void dfs(vector<int>& nums, int u){
        if(u == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!vis[i]){
                vis[i] = true;
                temp.push_back(nums[i]);
                dfs(nums, u + 1);
                vis[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size());
        dfs(nums, 0);
        return ans;
    }
};