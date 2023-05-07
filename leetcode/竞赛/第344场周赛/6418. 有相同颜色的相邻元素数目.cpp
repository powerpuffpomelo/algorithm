// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> nums(n, 0);
        int x = 0;
        for(auto q : queries){
            int idx = q[0], col = q[1];
            int before = 0, after = 0;
            if(idx - 1 >= 0 && nums[idx - 1] && nums[idx - 1] == nums[idx]) before++;
            if(idx + 1 < n && nums[idx] && nums[idx] == nums[idx + 1]) before++;
            nums[idx] = col;
            if(idx - 1 >= 0 && nums[idx - 1] && nums[idx - 1] == nums[idx]) after++;
            if(idx + 1 < n && nums[idx] && nums[idx] == nums[idx + 1]) after++;
            x = x + after - before;
            ans.push_back(x);
        }
        return ans;
    }
};