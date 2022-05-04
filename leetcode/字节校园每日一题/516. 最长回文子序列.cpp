class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(i < n - 1){
                dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
            }
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if(s[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
            }
        }
        return dp[0][n - 1];
    }
};