// ###################################################### 版本2 ###################################################### //
// 优化成2维dp
class Solution {
public:
    long long numberOfWays(string s) {
        s = ' ' + s;
        int n = s.size();
        vector<vector<long long>> dp(4, vector<long long>(2));
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 3; j++){
                if(j && s[i] == '0') dp[j][0] += dp[j - 1][1];
                if(j && s[i] == '1') dp[j][1] += dp[j - 1][0];
            }
        }
        return dp[3][0] + dp[3][1];
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，三维dp
class Solution {
public:
    // dp[i][j][k] 前i栋建筑，已经选择j个不一样的建筑，且最后一个选择的为k，总的方案数  j取值<=3, k = 0/1
    // dp[i][j][k] = 不选：dp[i - 1][j][k]  + 看看选第i个：dp[i - 1][j - 1][1 - k]
    // 
    static const int N = 1e5 + 10;
    long long dp[N][4][2];
    long long numberOfWays(string s) {
        s = ' ' + s;
        int n = s.size();
        if(n <= 3) return 0;
        memset(dp, 0, sizeof dp);
        //vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(4, vector<long long>(2))); 真就卡stl超时
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 3; j++){
                dp[i][j][0] = dp[i - 1][j][0];
                if(j && s[i] == '0') dp[i][j][0] += dp[i - 1][j - 1][1];
                dp[i][j][1] = dp[i - 1][j][1];
                if(j && s[i] == '1') dp[i][j][1] += dp[i - 1][j - 1][0];
            }
        }
        return dp[n - 1][3][0] + dp[n - 1][3][1];
    }
};