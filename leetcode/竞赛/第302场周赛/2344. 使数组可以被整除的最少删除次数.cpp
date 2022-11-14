// ###################################################### 版本1 ###################################################### //
class Solution {
public:
    int gcd(int a, int b){
        return b ? gcd(b, a % b) : a;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int all_gcd = 0;   // gcd初值可以设成0，不会影响最终结果
        for(auto x : numsDivide){
            all_gcd = gcd(all_gcd, x);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(all_gcd % nums[i] == 0) return i;
        }
        return -1;
    }
};