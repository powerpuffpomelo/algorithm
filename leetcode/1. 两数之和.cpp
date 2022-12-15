// ###################################################### 版本2 ###################################################### //
// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2id;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(num2id.count(target - nums[i])){
                ans = vector<int>({i, num2id[target - nums[i]]});
                break;
            }else{
                num2id[nums[i]] = i;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> num2id;
        for(int i = 0; i < nums.size(); i++){
            num2id[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        vector<int> ans;
        while(i < j){
            if(nums[i] + nums[j] == target){
                ans.push_back(num2id[nums[i]][0]);
                if(nums[i] == nums[j]) ans.push_back(num2id[nums[i]][1]);
                else ans.push_back(num2id[nums[j]][0]);
                break;
            }
            if(nums[i] + nums[j] < target) i++;
            else j--;
        }
        return ans;
    }
};

