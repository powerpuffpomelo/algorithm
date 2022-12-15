// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        word1 = ' ' + word1;
        word2 = ' ' + word2;
        for(int i = 0; i <= n; i++) dp[i][0] = i;   // 记得初始化！
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1));
            }
        }
        return dp[n][m];
    }
};