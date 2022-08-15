// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int remainder[3] = {0};
        for(int i = 0; i < nums.size(); i++){
            int a = remainder[0] + nums[i];
            int b = remainder[1] + nums[i];
            int c = remainder[2] + nums[i];
            remainder[a % 3] = max(remainder[a % 3], a);
            remainder[b % 3] = max(remainder[b % 3], b);
            remainder[c % 3] = max(remainder[c % 3], c);
        }
        return remainder[0];
    }
};