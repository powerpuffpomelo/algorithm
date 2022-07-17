// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int all_gcd = numsDivide[0];
        for(int i = 1; i < numsDivide.size(); i++){
            all_gcd = gcd(all_gcd, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(all_gcd % nums[i] == 0) return i;
        }
        return -1;
    }
};