// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        s = ' ' + s, p = ' ' + p;
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j] == '?') dp[i][j] = i && dp[i - 1][j - 1];
                else if(p[j] == '*'){
                    for(int k = i; k >= 0; k--){
                        if(dp[k][j - 1]){
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
                else dp[i][j] = i && dp[i - 1][j - 1] && s[i] == p[j];
            }
        }
        return dp[n][m];
    }
};