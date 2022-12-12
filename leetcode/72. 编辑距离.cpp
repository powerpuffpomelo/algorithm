class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        word1 = ' ' + word1, word2 = ' ' + word2;
        int n = word1.size(), m = word2.size();
        dp = vector<vector<int>>(n, vector<int>(m));
        for(int i = 1; i < n; i++) dp[i][0] = i;   // 记得初始化！
        for(int j = 1; j < m; j++) dp[0][j] = j;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                int ad = 0;
                if(word1[i] != word2[j]) ad = 1;
                dp[i][j] = min(dp[i - 1][j - 1] + ad, min(dp[i][j - 1], dp[i - 1][j]) + 1);
            }
        }
        return dp[n - 1][m - 1];
    }
};