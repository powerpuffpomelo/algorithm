class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e5 + 10;
        int n = nums.size();
        for(int i = 0, j = 0, s = 0; j < n; j++){
            s += nums[j];
            while(s - nums[i] >= target) s -= nums[i++];
            if(s >= target && j - i + 1 < ans) ans = j - i + 1;
        }
        if(ans <= 1e5) return ans;
        else return 0;
    }
};