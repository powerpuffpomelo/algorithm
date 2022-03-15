// ###################################################### 版本1 ###################################################### //
// dp，由于乘积可能负负得正，所以递推的话维护两个变量，最小值最大值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], mmax = nums[0], mmin = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];
            int a = mmax * x, b = mmin * x;
            mmax = max(a, max(b, x)), mmin = min(a, min(b, x));
            ans = max(ans, mmax);
        }
        return ans;
    }
};