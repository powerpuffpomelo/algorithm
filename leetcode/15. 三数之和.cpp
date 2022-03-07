// todo 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){   // 这里如果写i < nums.size() - 2 会报错
            if(i && nums[i] == nums[i - 1]){ 
                continue;
            }
            int j = i + 1, k = n - 1, t = nums[i];
            while(j < k){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    j++;
                    continue;
                }
                if(t + nums[j] + nums[k] < 0) j++;
                else if(t + nums[j] + nums[k] > 0) k--;
                else{
                    ans.push_back({t, nums[j], nums[k]});
                    j++, k--;
                }
            }
        }
        return ans;
    }
};