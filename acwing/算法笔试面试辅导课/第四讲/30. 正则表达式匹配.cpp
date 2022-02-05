class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = 1;
        for(int i = 0; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(j + 1 < m + 1 && p[j + 1] == '*') continue;
                if(i && p[j] != '*'){
                    dp[i][j] = dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }else if(p[j] == '*'){
                    dp[i][j] = dp[i][j - 2] || i && dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[n][m];
    }
};