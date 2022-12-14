// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3, vector<int>(n + 1));  // dp[i][j] 代表 i枚鸡蛋操作j次最多能测多少层楼高
        for(int i = 1; i <= n; i++) dp[1][i] = i;
        for(int i = 1; i <= n; i++){
            dp[2][i] = dp[1][i - 1] + 1 + dp[2][i - 1];
            if(dp[2][i] >= n) return i;
        }
        return -1;
    }
};