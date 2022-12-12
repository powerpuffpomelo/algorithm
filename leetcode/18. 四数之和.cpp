// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    typedef long long LL;
    vector<vector<int>> ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 3 < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j + 2 < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                for(int k = j + 1, l = n - 1; k < l;){
                    if(k > j + 1 && nums[k] == nums[k - 1]){
                        k++;
                        continue;
                    }
                    LL ss = (LL)nums[i] + nums[j] + nums[k] + nums[l];  // 这里要注意，相加会爆int
                    if(ss < target) k++;
                    else if(ss > target) l--;
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};