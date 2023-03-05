// ###################################################### 版本1 ###################################################### //
// 多重背包
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        int mod = 1e9 + 7;
        vector<long long> dp(1010);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = target; j >= 0; j--){
                for(int k = 1; k <= types[i][0] && k * types[i][1] <= j; k++){
                    dp[j] = (dp[j] + dp[j - k * types[i][1]]) % mod;
                }
            }
        }
        return dp[target];
    }
};