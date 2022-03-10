// ###################################################### 版本1 ###################################################### //
// 记忆化搜索
class Solution {
    int ans = 0;
    vector<int> dp;
public:
    int cal(int x){
        if(dp[x]) return dp[x];
        else{
            dp[x] = x;
            for(int i = 1; i * 2 <= x; i++){
                dp[x] = max(dp[x], cal(i) * cal(x - i));
            }
        }
        return dp[x];
    }
    int integerBreak(int n) {
        dp = vector<int>(n + 1);
        int ans = 0;
        for(int i = 1; i * 2 <= n; i++){
            ans = max(ans, cal(i) * cal(n - i));
        }
        return ans;
    }
};