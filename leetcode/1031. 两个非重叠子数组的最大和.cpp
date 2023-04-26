// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> lf(n), ls(n), rf(n), rs(n);
        int lf_temp = 0, ls_temp = 0, rf_temp = 0, rs_temp = 0;
        for(int i = 0; i < n; i++){
            lf_temp += nums[i];
            ls_temp += nums[i];
            if(i - firstLen >= 0) lf_temp -= nums[i - firstLen];
            if(i - secondLen >= 0) ls_temp -= nums[i - secondLen];
            if(i) lf[i] = lf[i - 1], ls[i] = ls[i - 1];
            lf[i] = max(lf[i], lf_temp);
            ls[i] = max(ls[i], ls_temp);
        }
        for(int i = n - 1; i >= 0; i--){
            rf_temp += nums[i];
            rs_temp += nums[i];
            if(i + firstLen <= n - 1) rf_temp -= nums[i + firstLen];
            if(i + secondLen <= n - 1) rs_temp -= nums[i + secondLen];
            if(i != n - 1) rf[i] = rf[i + 1], rs[i] = rs[i + 1];
            rf[i] = max(rf[i], rf_temp);
            rs[i] = max(rs[i], rs_temp);
        }
        int ans = 0;
        for(int i = firstLen - 1; i + secondLen < n; i++){
            ans = max(ans, lf[i] + rs[i + 1]);
        }
        for(int i = secondLen - 1; i + firstLen < n; i++){
            ans = max(ans, ls[i] + rf[i + 1]);
        }
        return ans;
    }
};