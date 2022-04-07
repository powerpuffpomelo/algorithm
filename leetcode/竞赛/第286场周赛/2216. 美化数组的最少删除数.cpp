// ###################################################### 版本1 ###################################################### //
// 规则贪心
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n - 1; i++){
            if((i - k) % 2 == 0 && nums[i] == nums[i + 1]) k++;
        }
        return (n - k) % 2 == 0 ? k : k + 1;
    }
};