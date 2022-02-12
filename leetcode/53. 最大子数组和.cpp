class Solution {
public:
    int ans = -1e4 - 10;
    int maxSubArray(vector<int>& nums) {
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = max(temp, 0) + nums[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};