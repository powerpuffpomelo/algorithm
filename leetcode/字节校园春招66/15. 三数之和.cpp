// ###################################################### 版本1 ###################################################### //
//
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
                    j++, k--;   // 乖乖自己调jk比较保险
                }
            }
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = n - 1; j < k; j++){
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
                while(j < k && nums[i] + nums[j] + nums[k] > 0) k--;   // 务必注意k的限制
                if(k == j) continue;
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                }else if(nums[i] + nums[j] + nums[k] < 0){
                    continue;
                }
            }
        }
        return ans;
    }
};

