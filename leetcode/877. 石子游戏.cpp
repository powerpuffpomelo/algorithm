// ###################################################### 版本2 ###################################################### //
// 其实不用记录前缀和，dp[i][j]代表从i到j的盈亏状况最大值
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(len == 1) dp[i][j] = piles[i];
                else{
                    dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1] > 0;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，区间dp，dp[i][j]代表某人当前状态为 还剩从i到j堆石子 可以获得的最大石子数
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + piles[i - 1];
        for(int len = 1; len <= n; len++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                dp[i][j] = s[j] - s[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        if(dp[1][n] > s[n] / 2) return true;
        return false;
    }
};