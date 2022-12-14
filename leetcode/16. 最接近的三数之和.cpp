// ###################################################### 版本3 ###################################################### //
// 简洁双指针
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    j++;
                    continue;
                }
                int s = nums[i] + nums[j] + nums[k];
                if(abs(target - s) < abs(target - ans)) ans = s;
                if(s <= target) j++;
                else k--;
            }
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 无需去重；对每个j，都找到sum >= target的最小的k
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        pair<int, int> ans(INT_MAX, INT_MAX);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1, k = nums.size() - 1; j < k; j++){
                while(k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k--;
                int sum = nums[i] + nums[j] + nums[k];
                ans = min(ans, make_pair(abs(sum - target), sum));  // 右侧
                if(k - 1 > j){
                    sum = nums[i] + nums[j] + nums[k - 1];
                    ans = min(ans, make_pair(abs(sum - target), sum));  // 左侧
                }
            }
        }
        return ans.second;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans, dist = 1e9, n = nums.size();
        for(int i = 0; i < n - 2; i++){
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = n - 1; j < k;){
                while(j > i + 1 && j < n - 1 && nums[j] == nums[j - 1]) j++;
                if(j == n - 1) break;
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < dist){
                    dist = abs(sum - target);
                    ans = sum;
                }
                if(sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};